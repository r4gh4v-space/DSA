#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
extern struct Student* studentHead;

struct Student {
    int id;
    char name[50];
    struct Student* next;
};

struct Student* studentHead = NULL;

void addStudent() {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));

    printf("Enter Student ID: ");
    scanf("%d", &newStudent->id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", newStudent->name);

    newStudent->next = NULL;

    if (studentHead == NULL) {
        studentHead = newStudent;
    } else {
        struct Student* temp = studentHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }

    printf("Student added successfully!\n");
}

void displayStudents() {
    if (studentHead == NULL) {
        printf("No students found.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    struct Student* temp = studentHead;
    while (temp != NULL) {
        printf("ID: %d\tName: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}
