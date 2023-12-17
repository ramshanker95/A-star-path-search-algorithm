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
