#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern struct Student* studentHead;

struct Attendance {
    char subject[30];
    char date[15];
    char status[10];  
    struct Attendance* next;
};


struct Student {
    int id;
    char name[50];
    struct Student* next;
    struct Attendance* attendanceHead; 
};


struct Student* findStudent(int id) {
    struct Student* temp = studentHead;
    while (temp != NULL) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}


void markAttendance() {
    int id;
    char subject[30], date[15], status[10];

    printf("Enter Student ID: ");
    scanf("%d", &id);

    struct Student* student = findStudent(id);
    if (student == NULL) {
        printf("Student not found.\n");
        return;
    }

    printf("Enter Subject: ");
    scanf(" %[^\n]", subject);
    printf("Enter Date (DD-MM-YYYY): ");
    scanf(" %[^\n]", date);
    printf("Enter Status (Present/Absent): ");
    scanf(" %[^\n]", status);

    struct Attendance* newNode = (struct Attendance*)malloc(sizeof(struct Attendance));
    strcpy(newNode->subject, subject);
    strcpy(newNode->date, date);
    strcpy(newNode->status, status);
    newNode->next = NULL;

    if (student->attendanceHead == NULL) {
        student->attendanceHead = newNode;
    } else {
        struct Attendance* temp = student->attendanceHead;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    printf("Attendance marked!\n");
}


void viewAttendanceByDate() {
    char date[15];
    printf("Enter Date to View (DD-MM-YYYY): ");
    scanf(" %[^\n]", date);

    struct Student* s = studentHead;
    printf("\n--- Attendance on %s ---\n", date);

    while (s != NULL) {
        struct Attendance* a = s->attendanceHead;
        int found = 0;
        while (a != NULL) {
            if (strcmp(a->date, date) == 0) {
                printf("ID: %d | Name: %s | Subject: %s | Status: %s\n", s->id, s->name, a->subject, a->status);
                found = 1;
            }
            a = a->next;
        }
        s = s->next;
    }
}


void deleteAttendance() {
    int id;
    char date[15], subject[30];

    printf("Enter Student ID: ");
    scanf("%d", &id);
    struct Student* student = findStudent(id);
    if (student == NULL) {
        printf("Student not found.\n");
        return;
    }

    printf("Enter Date (DD-MM-YYYY): ");
    scanf(" %[^\n]", date);
    printf("Enter Subject: ");
    scanf(" %[^\n]", subject);

    struct Attendance* curr = student->attendanceHead;
    struct Attendance* prev = NULL;

    while (curr != NULL) {
        if (strcmp(curr->date, date) == 0 && strcmp(curr->subject, subject) == 0) {
            if (prev == NULL) {
                student->attendanceHead = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("Attendance deleted.\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Attendance record not found.\n");
}
