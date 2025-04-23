#include <stdio.h>  
#include <stdlib.h> 

void addStudent();
void displayStudents();

void markAttendance();
void viewAttendanceByDate();
void deleteAttendance();

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
        fflush(stdout); 
        scanf("%d", &choice);

        printf("Choice: %d\n", choice);  

        switch(choice) {
            case 1:
                addStudent();  
                break;
            case 2:
                displayStudents();  
                break;
            case 3:
                markAttendance();  
                break;
            case 4:
                viewAttendanceByDate();  
                break;
            case 5:
                deleteAttendance();  
                break;
            case 6:
                searchStudentAttendance(); 
                break;
            case 7:
                subjectWiseAttendance(); 
                break;
            case 8:
                overallAttendanceReport();  
                break;
            case 0:
                printf("Exiting...\n");
                exit(0); 
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
int main() {
    menu();
    return 0;
}

