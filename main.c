#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 32
#define ASSIGNMENT_COUNT 3

struct Vector {
    void *data;
    size_t size;
    size_t capacity;
};

struct Student {
    char name[BUFFER_SIZE];
    double scores[ASSIGNMENT_COUNT];
    double total_score;
    double average_score;
};

struct Vector *new_vector(size_t initial_size) {
    struct Vector *vec = malloc(sizeof(struct Vector));
    vec->data = (struct Student *) malloc((initial_size < 1 ? 1 : initial_size) * sizeof(struct Student));
    if (!vec->data) {
        perror("Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    vec->size = 0;
    vec->capacity = initial_size < 1 ? 1 : initial_size;
    return vec;
}

void resize_vector(struct Vector **vec, size_t new_size) {
    (*vec)->data = (struct Student *) realloc((*vec)->data, new_size * sizeof(struct Student));
    if (!(*vec)->data) {
        perror("Failed to reallocate memory.\n");
        exit(EXIT_FAILURE);
    }
    (*vec)->capacity = new_size;
}

void push_back(struct Vector **vec, struct Student *student) {
    if ((*vec)->size == (*vec)->capacity) {
        resize_vector(vec, (*vec)->capacity * 2);
    }
    struct Student *students = (*vec)->data;
    students[(*vec)->size++] = *student;
}

void exit_program() {
    printf("Bye!!!\n");
    exit(EXIT_SUCCESS);
}

struct Student *new_student() {
    struct Student *student = malloc(sizeof(struct Student));
    strncpy(student->name, "", BUFFER_SIZE);
    
    for (size_t i = 0; i < ASSIGNMENT_COUNT; ++i) {
        student->scores[i] = 0.0;
    }
    student->total_score = 0.0;
    student->average_score = 0.0;
    return student;
}

void request_data(struct Vector **vec) {
    char choice = '\0';

    do {
        size_t student_count = 0;
        printf("\nEnter number of students : ");
        scanf(" %zu", &student_count);
        while (getchar() != '\n'); // clear input buffer

        if (student_count == 0) {
            exit_program();
        }

        for (size_t i = 0; i < student_count; ++i) {
            struct Student *student = new_student();
            printf("\nEnter student %zu name : ", i + 1);
            fgets(student->name, BUFFER_SIZE, stdin);
            student->name[strcspn(student->name, "\n")] = '\0'; // remove newline character from name

            for (size_t j = 0; j < ASSIGNMENT_COUNT; ++j) {
                printf("Enter assignment %zu score : ", j + 1);
                scanf(" %lf", &student->scores[j]);
                while (getchar() != '\n');

                student->total_score += student->scores[j];
            }
            student->average_score = student->total_score / ASSIGNMENT_COUNT;
            push_back(vec, student);
        }

        printf("\ncontinue (y/n) ? ");
        scanf(" %c", &choice);
    } while (choice != 'n');
}

void print_data(struct Vector *vec) {
    printf("\n%-32s %-8s\n", "NAME", "AVERAGE");
    struct Student *students = vec->data;
    for (size_t i = 0; i < vec->size; ++i) {
        printf("%-32s %-8.2lf\n", students[i].name, students[i].average_score);
    }
}

int main() {
    struct Vector *vec = new_vector(0);
    request_data(&vec);
    print_data(vec);
    free(vec->data);
    free(vec);
}