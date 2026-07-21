# Maze Solver with Recursion[cite: 1]

**Fundamentals of Computer Programming Lab Project - Fall 2025**[cite: 1]  
* **Instructor:** Dr. Bushra Qayum[cite: 1]  
* **Lab Engineer:** Ms. Zainab Zahid[cite: 1]  
* **Deadline:** 15 December 2025[cite: 1]  

---

## 👥 Group Members[cite: 1]

| Role | Name | Responsibility |
| :--- | :--- | :--- |
| **Team Leader**[cite: 1] | Syed Zulqarnain Haider[cite: 1] | Main Logic and Menu System[cite: 1] |
| **1st Member**[cite: 1] | Hibbah Fatima[cite: 1] | File Handling (Input)[cite: 1] |
| **2nd Member**[cite: 1] | Gul e Maheen Shah[cite: 1] | Coordinates and Recursion Logic[cite: 1] |
| **3rd Member**[cite: 1] | Seema Kataria[cite: 1] | Output and Visualization[cite: 1] |

---

## 📑 Table of Contents[cite: 1]
1. [Problem Statement](#-1-problem-statement)[cite: 1]
2. [Objectives](#-2-objectives)[cite: 1]
3. [Project Overview](#-3-project-overview)[cite: 1]
4. [Code Logic and Implementation](#-4-code-logic-and-implementation)[cite: 1]
5. [Tools Used](#-5-tools-used)[cite: 1]
6. [Flow Chart](#-6-flow-chart)[cite: 1]

---

## 1. ❓ Problem Statement[cite: 1]

In the field of computer science, pathfinding is a fundamental problem used in robotics, GPS navigation, and game development[cite: 1]. A maze consists of walls (`#`) and open paths, and the challenge is to determine a valid route from a specific Start (`S`) point to an Exit (`E`) point without crossing walls[cite: 1]. 

The problem addressed in this project is to develop a C++ program that automates this process[cite: 1]. Instead of manual solving, the program must intelligently explore the grid using recursion, identify the correct path, and utilize backtracking to recover from dead ends[cite: 1].

---

## 2. 🎯 Objectives[cite: 1]

The primary objectives of this lab project are:[cite: 1]
* To implement File Handling to read maze layouts dynamically from a text file (`input.txt`)[cite: 1].
* To utilize Recursion to navigate through the 2D grid[cite: 1].
* To apply Backtracking logic to handle dead ends and find the correct path[cite: 1].
* To display the final solution visually in the console using ANSI/Windows colors and save the result to `output.txt`[cite: 1].
* To generate a trace log (`trace.txt`) that records the recursive flow for debugging and analysis[cite: 1].

---

## 3. 📖 Project Overview[cite: 1]

This project is a console-based application written in C++[cite: 1]. It allows the user to load a maze from a default file or a custom file[cite: 1]. The maze is stored in a 2D character array[cite: 1]. The program finds the starting coordinates and initiates a recursive function `find_path`[cite: 1]. This function marks the path with asterisks (`*`) and explores four directions (Right, Down, Left, Up)[cite: 1]. If the exit is found, the path is highlighted in Green[cite: 1]. If the path is blocked, the algorithm backtracks[cite: 1].

---

## 4. ⚙️ Code Logic and Implementation[cite: 1]

### 🌐 A. Global Variables and Setup[cite: 1]
To ensure efficient memory access across recursive calls without passing heavy data structures, global variables are utilized:[cite: 1]
* `char maze_arr[100][100]`: A static 2D array to hold the maze grid[cite: 1].
* `int Rows`, `Cols`: Dynamic counters to store the actual size of the loaded maze[cite: 1].
* `start_Row`, `start_Col`, `end_Row`, `end_Col`: To store the coordinates of `S` and `E`[cite: 1].
* `total_steps`: An integer to count the total number of recursive calls[cite: 1].

### 📂 B. Menu and File Handling (Input)[cite: 1]
* The program begins by offering a menu implemented in `show_menu()` allowing the user to choose between the default `input.txt` or a custom file[cite: 1].
* The `read(string file_name)` function opens the file and reads it line-by-line using `getline`[cite: 1].
* **Space Handling:** The code includes specific logic to ignore spaces, tabs, and carriage returns (`if(letter != ' '...`) ensuring only valid maze characters are stored[cite: 1].
* **Dynamic Sizing:** The `Rows` and `Cols` variables are updated automatically based on the file content[cite: 1].

### 📍 C. Coordinate Scanning[cite: 1]
Before starting the recursion, the `scan_startAndend()` function iterates through the populated 2D array:[cite: 1]
* It searches for the character `S` to set the starting point[cite: 1].
* It searches for `E` to confirm the exit location[cite: 1].

### 🔄 D. Recursive Pathfinding (`find_path`)[cite: 1]
1. **Base Cases (Stopping Conditions):**[cite: 1]
   * *Boundary Check:* If `r` or `c` are outside the matrix limits, return `false`[cite: 1].
   * *Obstacle Check:* If the cell is a Wall (`#`) or already part of the current path (`*`), return `false`[cite: 1].
   * *Success:* If the cell contains `E`, log the success to `trace.txt` and return `true`[cite: 1].
2. **Recursive Steps:**[cite: 1]
   * The current cell is temporarily marked with `*` to indicate it is being visited[cite: 1].
   * The function recursively calls itself in the following order: Right (`c+1`), Down (`r+1`), Left (`c-1`), Up (`r-1`)[cite: 1].
   * If any of these return `true`, the function propagates `true` up the stack[cite: 1].
3. **Backtracking:**[cite: 1]
   * If all four directions return `false` (meaning a dead end), the function performs backtracking[cite: 1].
   * It restores the cell to its original state using the temp variable (`maze_arr[r][c] = temp`)[cite: 1].
   * It logs the backtracking action to `trace.txt` and returns `false`[cite: 1].

### 🎨 E. Output and Visualization[cite: 1]
The `saveO(bool found)` function handles the final display:[cite: 1]
* **Console Output:** It iterates through the grid utilizing the `windows.h` library and `SetConsoleTextAttribute` to print the path (`*`) and success messages in Green (color code 10) and Errors in Red (color code 12)[cite: 1].
* **File Output:** The solved maze is simultaneously written to `output.txt` as required[cite: 1].
* **Trace Log:** Throughout the execution, steps are recorded in `trace.txt`[cite: 1].

---

## 5. 🛠️ Tools Used[cite: 1]

* **Language:** C++ (Core Logic)[cite: 1]
* **IDE:** Dev-C++[cite: 1]
* **Libraries:** `<iostream>` & `<fstream>` for input/output and file operations, `<windows.h>` for coloring console output, `<string>` for file name manipulation[cite: 1]
* **Diagramming:** Mermaid.js for flowcharts[cite: 1]

---

## 6. 📊 Flow Chart[cite: 1]

Below is the flowchart representing the logic of the `find_path` function used in the project[cite: 1]:
*(Refer to your repository image assets to embed the flowchart diagram visual here)*[cite: 1]
