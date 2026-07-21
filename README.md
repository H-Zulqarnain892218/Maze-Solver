# Maze Solver with Recursion
---

## 👥 Made By

| Name |
| :--- |
| Syed Zulqarnain Haider |

---

## 📑 Table of Contents
1. [Problem Statement](#-1-problem-statement)
2. [Objectives](#-2-objectives)
3. [Project Overview](#-3-project-overview)
4. [Code Logic and Implementation](#-4-code-logic-and-implementation)
5. [Tools Used](#-5-tools-used)
6. [Flow Chart](#-6-flow-chart)

---

## 1. ❓ Problem Statement

In the field of computer science, pathfinding is a fundamental problem used in robotics, GPS navigation, and game development. A maze consists of walls (`#`) and open paths, and the challenge is to determine a valid route from a specific Start (`S`) point to an Exit (`E`) point without crossing walls. 

The problem addressed in this project is to develop a C++ program that automates this process. Instead of manual solving, the program must intelligently explore the grid using recursion, identify the correct path, and utilize backtracking to recover from dead ends.

---

## 2. 🎯 Objectives

The primary objectives of this lab project are:
* To implement File Handling to read maze layouts dynamically from a text file (`input.txt`).
* To utilize Recursion to navigate through the 2D grid.
* To apply Backtracking logic to handle dead ends and find the correct path.
* To display the final solution visually in the console using ANSI/Windows colors and save the result to `output.txt`.
* To generate a trace log (`trace.txt`) that records the recursive flow for debugging and analysis.

---

## 3. 📖 Project Overview

This project is a console-based application written in C++. It allows the user to load a maze from a default file or a custom file. The maze is stored in a 2D character array. The program finds the starting coordinates and initiates a recursive function `find_path`. This function marks the path with asterisks (`*`) and explores four directions (Right, Down, Left, Up). If the exit is found, the path is highlighted in Green. If the path is blocked, the algorithm backtracks.

---

## 4. ⚙️ Code Logic and Implementation

### 🌐 A. Global Variables and Setup
To ensure efficient memory access across recursive calls without passing heavy data structures, global variables are utilized:
* `char maze_arr[100][100]`: A static 2D array to hold the maze grid.
* `int Rows`, `Cols`: Dynamic counters to store the actual size of the loaded maze.
* `start_Row`, `start_Col`, `end_Row`, `end_Col`: To store the coordinates of `S` and `E`.
* `total_steps`: An integer to count the total number of recursive calls.

  <img width="702" height="605" alt="image" src="https://github.com/user-attachments/assets/22d9e02c-6560-49ca-9c5c-d7ff824dc6cc" />


### 📂 B. Menu and File Handling (Input)
* The program begins by offering a menu implemented in `show_menu()` allowing the user to choose between the default `input.txt` or a custom file.
* The `read(string file_name)` function opens the file and reads it line-by-line using `getline`.
* **Space Handling:** The code includes specific logic to ignore spaces, tabs, and carriage returns (`if(letter != ' '...`) ensuring only valid maze characters are stored.
* **Dynamic Sizing:** The `Rows` and `Cols` variables are updated automatically based on the file content.

  <img width="801" height="978" alt="image" src="https://github.com/user-attachments/assets/be066dce-ce90-4a97-9275-bfbf88e6ffd7" />


### 📍 C. Coordinate Scanning
Before starting the recursion, the `scan_startAndend()` function iterates through the populated 2D array:
* It searches for the character `S` to set the starting point.
* It searches for `E` to confirm the exit location.

### 🔄 D. Recursive Pathfinding (`find_path`)
1. **Base Cases (Stopping Conditions):**
   * *Boundary Check:* If `r` or `c` are outside the matrix limits, return `false`.
   * *Obstacle Check:* If the cell is a Wall (`#`) or already part of the current path (`*`), return `false`.
   * *Success:* If the cell contains `E`, log the success to `trace.txt` and return `true`.
2. **Recursive Steps:**
   * The current cell is temporarily marked with `*` to indicate it is being visited.
   * The function recursively calls itself in the following order: Right (`c+1`), Down (`r+1`), Left (`c-1`), Up (`r-1`).
   * If any of these return `true`, the function propagates `true` up the stack.
3. **Backtracking:**
   * If all four directions return `false` (meaning a dead end), the function performs backtracking.
   * It restores the cell to its original state using the temp variable (`maze_arr[r][c] = temp`).
   * It logs the backtracking action to `trace.txt` and returns `false`.
  
   <img width="935" height="1281" alt="image" src="https://github.com/user-attachments/assets/81dadb28-07e5-4953-a27e-b88757470eec" />


### 🎨 E. Output and Visualization
The `saveO(bool found)` function handles the final display:
* **Console Output:** It iterates through the grid utilizing the `windows.h` library and `SetConsoleTextAttribute` to print the path (`*`) and success messages in Green (color code 10) and Errors in Red (color code 12).
* **File Output:** The solved maze is simultaneously written to `output.txt` as required.
* **Trace Log:** Throughout the execution, steps are recorded in `trace.txt`.

  <img width="586" height="714" alt="image" src="https://github.com/user-attachments/assets/7c3b427a-cbbd-4cd1-a471-9be1d9be70a2" />


---

## 5. 🛠️ Tools Used

* **Language:** C++ (Core Logic)
* **IDE:** Dev-C++
* **Libraries:** `<iostream>` & `<fstream>` for input/output and file operations, `<windows.h>` for coloring console output, `<string>` for file name manipulation
* **Diagramming:** Mermaid.js for flowcharts[cite: 1]

---

## 6. 📊 Flow Chart
<img width="450" height="1327" alt="image" src="https://github.com/user-attachments/assets/c3e09edb-fde2-4b7b-8a1f-079786fd06ec" />

Below is the flowchart representing the logic of the `find_path` function used in the project.

