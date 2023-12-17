#include <Arduino.h>
#include <math.h>
#define GRID_WIDTH 10
#define GRID_HEIGHT 10
// Define the size of the list to store coordinates
const int maxCoordinates = 100; // Change this based on your needs
// Create an array to store coordinates
int coordinates[maxCoordinates][2]; // Assuming each coordinate has x and y values
// Counter to keep track of the number of coordinates stored
int coordinateCount = 0;
//int count = 0;
char grid[GRID_WIDTH][GRID_HEIGHT] = {
  {'0', '0', '0', '0', '0', '0', '0', '0', '1', '0'},
  {'0', '0', '1', '1', '0', '0', '1', '1', '0', '0'},
  {'0', '0', '1', '0', '0', '0', '0', '1', '0', '0'},
  {'0', '0', '0', '0', '1', '0', '0', '1', '0', '0'},
  {'1', '0', '0', '0', '1', '0', '1', '1', '0', '0'},
  {'0', '0', '0', '0', '0', '0', '1', '1', '0', '0'},
  {'0', '0', '1', '1', '0', '0', '0', '0', '0', '0'},
  {'0', '0', '1', '0', '0', '0', '0', '0', '0', '0'},
  {'0', '0', '0', '0', '1', '0', '0', '1', '1', '0'},
  {'1', '0', '0', '0', '0', '1', '1', '0', '0', '0'}
};

struct Node {
  int x, y;
  int g, h, f;
  Node* parent;
};

Node* openSet[GRID_WIDTH * GRID_HEIGHT];
Node* closedSet[GRID_WIDTH * GRID_HEIGHT];
int openSetSize = 0;
int closedSetSize = 0;

char path[GRID_WIDTH][GRID_HEIGHT];

struct Queue {
  Node* items[GRID_WIDTH * GRID_HEIGHT];
  int front;
  int rear;
  int size;
};

Queue openSetQueue;

void initQueue(Queue& q) {
  q.front = 0;
  q.rear = -1;
  q.size = 0;
}

void enqueue(Queue& q, Node* item) {
  if (q.size < GRID_WIDTH * GRID_HEIGHT) {
    q.rear = (q.rear + 1) % (GRID_WIDTH * GRID_HEIGHT);
    q.items[q.rear] = item;
    q.size++;
  }
}

Node* dequeue(Queue& q) {
  if (q.size > 0) {
    Node* item = q.items[q.front];
    q.front = (q.front + 1) % (GRID_WIDTH * GRID_HEIGHT);
    q.size--;
    return item;
  }
  return nullptr;
}

bool isValid(int x, int y) {
//  Serial.println("isValid");
  return (x >= 0) && (x < GRID_WIDTH) && (y >= 0) && (y < GRID_HEIGHT) && (grid[x][y] != '1');
}

int heuristic(int x1, int y1, int x2, int y2) {
  return sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2))); // Manhattan distance
}

void addToOpenSet(Node* node) {
  openSet[openSetSize++] = node;
}

Node* removeFromOpenSet() {
  int lowestFIndex = 0;
  for (int i = 1; i < openSetSize; i++) {
    if (openSet[i]->f < openSet[lowestFIndex]->f) {
      lowestFIndex = i;
    }
  }

  Node* lowestFNode = openSet[lowestFIndex];
  for (int i = lowestFIndex; i < openSetSize - 1; i++) {
    openSet[i] = openSet[i + 1];
  }
  openSetSize--;

  return lowestFNode;
}

bool isInClosedSet(int x, int y) {
  for (int i = 0; i < closedSetSize; i++) {
    if ((closedSet[i]->x == x) && (closedSet[i]->y == y)) {
      return true;
    }
  }
  return false;
}

void reconstructPath(Node* current) {
//  Serial.println("Shortest Path (x, y):");
  while (current != nullptr) {
    path[current->x][current->y] = '*';
//    Serial.print("(" + String(current->x) + "," + String(current->y) + ")");
    int x_val = int(current->x);
    int y_val = int(current->y);
    addCoordinate(x_val,y_val);
    current = current->parent;
  }
  Serial.println(' ');
}

void printPath() {
  Serial.println(' ');
  Serial.println("Path:");
  for (int i = 0; i < GRID_WIDTH; i++) {
    for (int j = 0; j < GRID_HEIGHT; j++) {
      Serial.print(path[i][j]);
      Serial.print(' ');
    }
    Serial.println();
  }
}
//----------------------------------------
// Function to add a coordinate to the listint 
int count = 0;
void addCoordinate(int x, int y) {
  if (count < maxCoordinates) {
    coordinates[count][0] = x;
    coordinates[count][1] = y;
    coordinateCount++;
    count=count+1;
  } else {
    Serial.println("Coordinate list is full!");
  }
}

// Function to reverse the list of coordinates
void reverseCoordinates() {
  for (int i = 0; i < count / 2; i++) {
    // Swap the i-th and (coordinateCount - i - 1)-th coordinates
    int tempX = coordinates[i][0];
    int tempY = coordinates[i][1];
    coordinates[i][0] = coordinates[count - i - 1][0];
    coordinates[i][1] = coordinates[count - i - 1][1];
    coordinates[count - i - 1][0] = tempX;
    coordinates[count - i - 1][1] = tempY;
  }
  Serial.println("Coordinates (x,y):");
  for (int i = 0; i < count; i++) {
    Serial.print("(" + String(coordinates[i][0]) + "," + String(coordinates[i][1]) + ")");
  }
  Serial.println();
}
//-----------------------------------------

void aStar(int ix,int iy,int fx,int fy) {
  Node* startNode = new Node{ix, iy, 0, 0, 0, nullptr};
  Node* goalNode = new Node{fx, fy, 0, 0, 0, nullptr};
  addToOpenSet(startNode);

  while (openSetSize > 0) {
    Node* current = removeFromOpenSet();

    if (current->x == goalNode->x && current->y == goalNode->y) {
      reconstructPath(current);
      return;
    }

    closedSet[closedSetSize++] = current;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
      int neighborX = current->x + dx[i];
      int neighborY = current->y + dy[i];

      if (!isValid(neighborX, neighborY) || isInClosedSet(neighborX, neighborY)) {
        continue;
      }

      int tentativeG = current->g + 1;
      bool foundBetterPath = false;

      for (int j = 0; j < openSetSize; j++) {
        if (openSet[j]->x == neighborX && openSet[j]->y == neighborY) {
          if (tentativeG < openSet[j]->g) {
            openSet[j]->g = tentativeG;
            foundBetterPath = true;
            openSet[j]->parent = current;
          }
          break;
        }
      }

      if (!foundBetterPath) {
        Node* neighbor = new Node{neighborX, neighborY, tentativeG, heuristic(neighborX, neighborY, goalNode->x, goalNode->y), 0, current};
        addToOpenSet(neighbor);
      }
    }
  }
  Serial.println("No path found.");
}

void setup() {
  Serial.begin(115200);
  initQueue(openSetQueue);
  for (int i = 0; i < GRID_WIDTH; i++) {
    for (int j = 0; j < GRID_HEIGHT; j++) {
      path[i][j] = ' ';
    }
  }
  static bool pathPrinted = false; // Added to print the path only once
    if (!pathPrinted) {
      aStar(0,0,9,8);
      printPath();
      reverseCoordinates();
      pathPrinted = true;
      }
}
void loop() 
{
//  if(Serial.available()>0)
//  {
//    int fx = Serial.readStringUntil(',').toInt();
//    int fy = Serial.readStringUntil('\n').toInt();
//    static bool pathPrinted = false; // Added to print the path only once
//    if (!pathPrinted) {
//      aStar(0,0,9,8);
//      printPath();
//      reverseCoordinates();
//      pathPrinted = true;
//      }
//    }
//  }
  while (openSetQueue.size > 0) {
    Serial.print(openSetQueue.size);
    Node* node = dequeue(openSetQueue);
    delete node;
  }
}
