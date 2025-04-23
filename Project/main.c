#include <stdio.h>  // For printf, scanf
#include <stdlib.h> // For exit

// Declarations for functions in student.c
void addStudent();
void displayStudents();

// Declarations for functions in attendance.c
void markAttendance();
void viewAttendanceByDate();
void deleteAttendance();

// Declarations for functions in report.c
void searchStudentAttendance();
void subjectWiseAttendance();
void overallAttendanceReport();

void menu() {
    int choice;
    while (1) {
        printf("\n========== Student Attendance Monitoring System ==========\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Mark Attendance\n");
        printf("4. View Attendance by Date\n");
        printf("5. Delete Attendance\n");
        printf("6. Search Student Attendance\n");
        printf("7. Per Subject Attendance\n");
        printf("8. Overall Attendance Report\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        fflush(stdout); // Ensure that the prompt is printed before waiting for input
        scanf("%d", &choice);

        printf("Choice: %d\n", choice);  // Print the user input

        switch(choice) {
            case 1:
                addStudent();  // Call addStudent()
                break;
            case 2:
                displayStudents();  // Call displayStudents()
                break;
            case 3:
                markAttendance();  // Call markAttendance()
                break;
            case 4:
                viewAttendanceByDate();  // Call viewAttendanceByDate()
                break;
            case 5:
                deleteAttendance();  // Call deleteAttendance()
                break;
            case 6:
                searchStudentAttendance();  // Call searchStudentAttendance()
                break;
            case 7:
                subjectWiseAttendance();  // Call subjectWiseAttendance()
                break;
            case 8:
                overallAttendanceReport();  // Call overallAttendanceReport()
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);  // Exit the program
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
int main() {
    menu();
    return 0;
}

