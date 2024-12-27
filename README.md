# Student Score Management Program

This program allows you to manage student scores for assignments. It collects student names and their scores, calculates the total and average scores, and displays the results.

## How to Use

1. **Enter the number of students**: The program will prompt you to enter the number of students.
2. **Enter student details**: For each student, enter the name and scores for three assignments.
3. **Continue or exit**: After entering the details for the specified number of students, you can choose to continue entering more students or exit the program.
4. **View results**: The program will display the names and average scores of all entered students.

## Example

**RESULT** <br>
Enter number of students : 2 <br>

Enter student 1 name : Andrew Muchangi <br>
Enter assignment 1 score : 21 <br>
Enter assignment 2 score : 22 <br>
Enter assignment 3 score : 24 <br>

Enter student 2 name : John Kariuki <br>
Enter assignment 1 score : 19 <br>
Enter assignment 2 score : 22 <br>
Enter assignment 3 score : 25 <br>

continue (y/n) ? y <br>

Enter number of students : 1 <br>

Enter student 1 name : Jane Doe <br>
Enter assignment 1 score : 21 <br>
Enter assignment 2 score : 21 <br>
Enter assignment 3 score : 18 <br>

continue (y/n) ? n <br>

| Name          | Average |
|---------------|---------|
| Andrew Muchangi   | 22.33   |
| John Kariuki  | 22.00   |
| Jane Doe      | 20.33   |

## Code Structure

- `main.c`: Contains the main logic of the program, including functions for managing vectors, collecting student data, and printing results.

## Functions

- `struct Vector *new_vector(size_t initial_size)`: Creates a new vector with the specified initial size.
- `void resize_vector(struct Vector **vec, size_t new_size)`: Resizes the vector to the new size.
- `void push_back(struct Vector **vec, struct Student *student)`: Adds a new student to the vector.
- `void exit_program()`: Exits the program with a goodbye message.
- `struct Student *new_student()`: Creates a new student with default values.
- `void request_data(struct Vector **vec)`: Collects student data from the user.
- `void print_data(struct Vector *vec)`: Prints the names and average scores of all students.

## Compilation

To compile the program, use the following command:

```sh
gcc -o student_scores main.c