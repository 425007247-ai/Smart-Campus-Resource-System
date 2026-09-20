# Smart Campus Student Resource Management System

## Project Overview

The Smart Campus Student Resource Management System is a C++ console-based application developed for NTC CC105 Data Structure. The system manages student records and campus resources using arrays, dynamic memory, searching algorithms, and matrix processing.

## Data Structures Used

### 1. Student List

The Student List stores student records such as Student ID, name, section, year level, and status.

Operations:
- Add student
- Display students
- Search student
- Update student
- Delete student

Implementation:

```cpp
Student students[MAX_STUDENTS];
```

The student records are stored using a static array.

### 2. Campus Resource List

The Campus Resource List stores campus resource information such as resource ID, name, type, and capacity.

Operations:
- Display resources
- Add resource
- Delete resource

Implementation:

```cpp
Resource *resources;
```

Dynamic memory allocation is used for the resource records.

## Static Array

The program uses:

```cpp
Student students[MAX_STUDENTS];
```

The static array stores up to 100 student records. Student records can be added, displayed, searched, updated, and deleted.

The program uses a loop to traverse the active student records.

## Dynamic Memory

The program uses a pointer for campus resources:

```cpp
Resource *resources = NULL;
```

Memory is dynamically allocated using:

```cpp
resources = new Resource[50];
```

The allocated memory is released before the program ends:

```cpp
delete[] resources;
resources = NULL;
```

This allows the program to properly release the dynamically allocated memory.

## Searching

The program uses Linear Search when finding student and resource records.

The search checks the records one by one until the matching ID is found or all records have been checked.

### Complexity

- Best Case: O(1)
- Worst Case: O(n)
- Average Case: O(n)

## Array Operations

The program performs the following array operations:

- Insertion
- Traversal
- Searching
- Updating
- Deletion

During student deletion, the records after the deleted student are shifted one position to the left.

## Matrix Processing

The system uses a 4 × 4 integer matrix to represent campus resource usage.

Rows represent departments:

- IT
- Engineering
- Business
- Education

Columns represent resources:

- Computers
- Rooms
- Library
- Equipment

The program can display the matrix and calculate the total resource usage for each department.

Matrix processing uses nested loops to access the rows and columns.

### Matrix Complexity

```text
O(n²)
```

## Main System Features

1. Add Student
2. Display Students
3. Search Student
4. Update Student
5. Delete Student
6. Manage Campus Resources
7. Display Resource Matrix
8. Analyze Resource Utilization
9. Generate Report
10. Exit

## Testing

The system was tested using different scenarios:

1. Display Students
2. Search Existing Student
3. Search Missing Student
4. Add Student
5. Duplicate Student ID
6. Update Student
7. Delete Student
8. Invalid Menu Choice
9. Display Resource Matrix
10. Analyze Resource Utilization

## Big-O Summary

| Operation | Complexity |
|---|---|
| Direct Array Access | O(1) |
| Array Traversal | O(n) |
| Linear Search | O(n) |
| Student Insertion | O(n) |
| Student Update | O(n) |
| Student Deletion | O(n) |
| Matrix Processing | O(n²) |

## Group Members

- Amores, Renedel
- Bernardo, Marvin
- Bulatao, Harvey M.
- Cajayon, Mark Erick

## Course Information

NTC_CC105 – Data Structure

National Teachers College  
School of Arts, Sciences and Technology  
BSIT – 2.4BSIT
