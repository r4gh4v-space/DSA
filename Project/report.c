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

extern struct Student* studentHead;
#include <stdio.h>
#include <string.h>

extern struct Student* studentHead;

void searchStudentAttendance() {
    int id;
    printf("Enter Student ID to Search: ");
    scanf("%d", &id);

    struct Student* student = studentHead;
    while (student != NULL) {
        if (student->id == id) {
            printf("\nAttendance for %s (ID: %d):\n", student->name, student->id);
            struct Attendance* a = student->attendanceHead;
            if (a == NULL) {
                printf("No attendance records.\n");
                return;
            }
            while (a != NULL) {
                printf("Subject: %s | Date: %s | Status: %s\n", a->subject, a->date, a->status);
                a = a->next;
            }
            return;
        }
        student = student->next;
    }
    printf("Student not found.\n");
}

void subjectWiseAttendance() {
    int id;
    char subject[30];
    printf("Enter Student ID: ");
    scanf("%d", &id);
    printf("Enter Subject Name: ");
    scanf(" %[^\n]", subject);

    struct Student* student = studentHead;
    while (student != NULL) {
        if (student->id == id) {
            int total = 0, present = 0;
            struct Attendance* a = student->attendanceHead;
            while (a != NULL) {
                if (strcmp(a->subject, subject) == 0) {
                    total++;
                    if (strcmp(a->status, "Present") == 0)
                        present++;
                }
                a = a->next;
            }
            if (total == 0) {
                printf("No records for subject %s\n", subject);
            } else {
                float percentage = ((float)present / total) * 100;
                printf("Subject: %s | Present: %d / %d (%.2f%%)\n", subject, present, total, percentage);
            }
            return;
        }
        student = student->next;
    }
    printf("Student not found.\n");
}

void overallAttendanceReport() {
    struct Student* student = studentHead;
    printf("\n--- Overall Attendance Report ---\n");

    while (student != NULL) {
        int total = 0, present = 0;
        struct Attendance* a = student->attendanceHead;
        while (a != NULL) {
            total++;
            if (strcmp(a->status, "Present") == 0)
                present++;
            a = a->next;
        }

        float percentage = (total > 0) ? ((float)present / total) * 100 : 0;
        printf("ID: %d | Name: %s | Attendance: %d/%d (%.2f%%)\n", student->id, student->name, present, total, percentage);
        student = student->next;
    }
}
