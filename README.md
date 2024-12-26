
# Get Next Line

## Overview

The **Get Next Line** project aims to implement a function in C that reads one line at a time from a file descriptor. This project introduces the use of static variables, memory management, and efficient file handling in C. It is part of the 42 school curriculum.

## Current Status

-   **Project Files**: Work in progress
-   **Makefile**: Under development
-   **Testing**: Initial tests planned

## Mandatory Requirements

-   Implement the function:
    
    ```c
    char *get_next_line(int fd);
    
    ```
    
-   Use only the allowed functions:
    -   `read`
    -   `malloc`
    -   `free`
-   Ensure the function works with standard input (stdin) and files.
-   Handle varying `BUFFER_SIZE` values efficiently.

## Restrictions

-   Global variables are forbidden.
-   Must comply with the 42 Norm.
-   File reading must occur only once (no use of `lseek`).

## Planned Features

1.  **Function Implementation**:
    -   Read and return one line at a time from a file descriptor.
    -   Include the newline character (`\n`) in the returned line unless at EOF.
2.  **Helper Utilities**:
    -   Implement functions like `ft_strlen`, `ft_strchr`, and `ft_strjoin` for string manipulation.
3.  **Bonus Features**:
    -   Manage multiple file descriptors simultaneously.
    -   Use a single static variable.

## Development Environment

-   **Dev Container**:
    -   GCC-based Docker image
    -   Preinstalled tools: `make`, `valgrind`, `gdb`
-   **VS Code Workspace**:
    -   Extensions: `C/C++`, `Makefile Tools`
    -   Configured for tab size and norm compliance

## To-Do List

-   Implement `get_next_line` logic
-   Write helper functions (`ft_strlen`, `ft_strjoin`, etc.)
-   Create comprehensive test cases
-   Finalize bonus features
-   Update this README with detailed documentation
