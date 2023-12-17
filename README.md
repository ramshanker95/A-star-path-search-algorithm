# A* Pathfinding Algorithm with Arduino

This repository contains an implementation of the A* pathfinding algorithm using Arduino for a specified grid. This algorithm finds the shortest path from a start point to an end point in a given grid while avoiding obstacles.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Customization](#customization)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This code implements the A* algorithm for pathfinding on a defined grid using Arduino. The grid is represented by a 2D array, and the algorithm finds the shortest path from the start point (0,0) to the end point (9,8), avoiding obstacles represented by '1's in the grid.

## Features

- A* pathfinding algorithm implementation.
- Grid-based pathfinding with obstacle avoidance.
- Tracking and printing the shortest path found.
- Reversing and storing the coordinates of the shortest path.

## Getting Started

To run this code, you'll need:
- Arduino IDE installed on your computer.
- An Arduino board connected to your computer.
- Necessary hardware setup (if required).

Clone the repository to your local machine and open the code in the Arduino IDE.

## Usage

1. Open the code in the Arduino IDE.
2. Upload the code to your Arduino board.
3. Monitor the Serial output to view the printed path and coordinates.

## Customization

You can customize the following aspects of the code:
- Grid size by modifying `GRID_WIDTH` and `GRID_HEIGHT`.
- Max coordinates to store by adjusting `maxCoordinates`.
- Starting and ending points by changing parameters in the `aStar()` function.

## Contributing

Contributions to improve or extend this implementation are welcome. To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-name`).
3. Make your changes and commit them (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-name`).
5. Create a new Pull Request.

##-------------------------------------------------------------------

# 1: Python implementation of A pathfinding algorithm:
This repository contains a Python code for finding the shortest path in a grid using the A* algorithm. 
It uses the Manhattan distance as the heuristic.

## Features:
  * Supports diagonal movements
  * Handles obstacles in the grid
  * Returns the shortest path as a list of coordinates

## Grid Definition
 The script defines a grid representing a map, where:
 ### 0 indicates a traversable cell.
 ### 1 indicates an obstacle or non-traversable cell.
 
 ## A* Algorithm Implementation
  The __astar()__ function executes the A* algorithm to find the shortest path:
  
  * It uses the Manhattan distance heuristic to estimate the cost between nodes.
  * Determines valid movements: up, down, left, right, and diagonals.
  * Reconstructs the shortest path from start to goal using a came_from dictionary.
  * 
## Usage:
  * Clone the repository.
  * Install the heapq library (pip install heapq).
  * Run the pathfinding.py script.
  * Enter the starting and ending points in the format Ix,Iy,Fx,Fy where I and F represent initial and final positions, and x and y represent their coordinates.
  * The script will print the shortest path as a list of coordinates (optional: uncomment the line print(node) in the code to see all visited nodes).

## Example:
  * $ python pathfinding.py 
  * Please enter the start and goal value(Ix,Iy,Fx,Fy): 
  * Please enter Ix value: 0
  * Please enter Iy value: 0 
  * Please enter fx value: 13 
  * Please enter fy value: 13
    
  ### [(0, 0), (1, 0), (2, 0), (3, 0), (3, 1), (3, 2), (3, 3), (4, 3), (5, 3), (5, 4), (5, 5), (5, 6), (5, 7), (5, 8), (5, 9), (5, 10), (5, 11), (5, 12), (5, 13)]

## Notes:
  * You can modify the grid variable to define different maze layouts.
  * The code currently uses basic input validation. You can improve it by adding more complex checks and error handling.
  * This is a basic implementation of A*. You can explore further advanced techniques and optimizations.
  * Feel free to contribute to this project by improving the code or adding new features.
  
  ### Happy pathfinding!
  
