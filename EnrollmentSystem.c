/*
    *ENROLLMENT SYSTEM*

    MGA GUSTO KO MANGYARE:
    1. MAGDISPLAY NG LANDING PAGE
    2. MAGKAROON NG THREE FUNCTIONS:
        1.) ENROLL
            - SELECT COURSE/PROGRAM
            - FILL UP BASIC INFORMATION
                - FULL NAME
                - AGE
                - NATIONALITY
                - GENERAL WEIGHTED AVERAGE
                - DATE OF BIRTH
                - CONTACT NUMBER: +63 
        2.) VIEW YUNG MGA PROGRAMS NA INOOFFER
        3.) ABOUT THE UNIVERSITY
        4.) EXIT

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char FullName[50];
    int age;
    char Nationality[15];
    double GWA;
    char DateOfBirth[30];
    char ContactNumber[13];

    struct {
        char FullName[50];
        char Occupation[50];
        char ContactNumber[13];
    } MotherInfo;

    struct {
        char FullName[50];
        char Occupation[50];
        char ContactNumber[13];
    } FatherInfo;

}Student;

typedef struct 
{
    char Name[70];
    char Code[10];
    int units;
    char department[50];
}Program;

void WelcomePage() {

    printf("=================================================\n");
    printf("\tWELCOME TO ENCHONG DEE UNIVERSITY\n");
    printf("\t--- WHERE EDUCATION IS VALUED ---\n");
    printf("=================================================\n");
    printf("\t    PRESS [ENTER] TO EXPLORE!\n");
    printf("=================================================\n");
    while (getchar() != '\n');
    system("cls");
}

int displayDashboard() {

    int choice = 0;

    do
    {
        printf("=================================================\n");
        printf("\tWELCOME TO ENCHONG DEE UNIVERSITY\n");
        printf("\t--- WHERE EDUCATION IS VALUED ---\n");
        printf("=================================================\n");
        printf("\n      [1] ENROLL    ");
        printf("\t[2] VIEW PROGRAMS");
        printf("\n\n      [3] ABOUT US");
        printf("\t[4] EXIT");

        printf("\n\nSELECT: ");
        scanf("%d", &choice);

    } while (choice > 4 || choice < 1);
    
    return choice;
    
}

void invalid() {

    printf("\nINVALID INPUT!");
    printf("\nPLEASE TRY AGAIN");
}


int main() {

    Program program[5] = {
        {
            .Name = "Bachelor of Science in Information Technology",
            .Code = "BSIT",
            .department = "Computer Studies Department",
            .units = 150
        },
        {
            .Name = "Bachelor of Science in Information System",
            .Code = "BSIS",
            .department = "Computer Studies Department",
            .units = 146
        },
        {
            .Name = "Bachelor of Science in Computer Science",
            .Code = "BSCS",
            .department = "Computer Studies Department",
            .units = 153
        },
        {
            .Name = "Bachelor of Science in Entertainment and Multimedia Computing",
            .Code = "BSEMC",
            .department = "Computer Studies Department",
            .units = 143
        },
        {
            .Name = "Bachelor of Science in Computer Engineering",
            .Code = "BSCpE",
            .department = "Computer Studies Department",
            .units = 156
        }
    };


    Student student[10];
    int studentCount = 0;
    int userChoice = 0;
    int limit = 10;

    // FLAG VARIABLE

    char wishToReturn = '\0';

    int doneViewing = 0;
    int getUserChoiceToExitPage = 0;


    // START PROGRAM

    WelcomePage();

    while (doneViewing != 1)
    {
        userChoice = displayDashboard();

        if (userChoice == 1)
        {
            // code
        }
        else if (userChoice == 2)
        {
            printf("=================================================\n");
            printf("\t    --- PROGRAMS OFFERED ---\n");
            printf("=================================================\n");

            for (int i = 0; i < 5; i++)
            {
                printf("\n\nPROGRAM\t    : %-70s", program[i].Name);
                printf("\nCODE\t    : %-70s", program[i].Code);
                printf("\nDEPARTMENT  : %-70s", program[i].department);
                printf("\nUNITS\t    : %-70d", program[i].units);
                printf("\n\n-------------------------------------------------\n");

            }
            
            do
            {
                printf("\n\nPRESS R TO RETURN TO MAIN PAGE: ");
                scanf(" %c", &wishToReturn);

                    if (wishToReturn != 'R' && wishToReturn != 'r')
                    {
                        invalid();
                    }
            } while (wishToReturn != 'R' && wishToReturn != 'r');
            system("cls");
            doneViewing = 0;

        }
        else if (userChoice == 3)
        {
            /* code */
        }
        else if (userChoice == 4)
        {
            do
            {
                system("cls");
                printf("DO YOU REALLY WANT TO EXIT?");
                printf("\n[1] YES");
                printf("\n[2] NO");
                printf("\n\nSELECT: ");
                scanf("%d", &getUserChoiceToExitPage);     
                    
                    if (getUserChoiceToExitPage == 1)
                    {
                        system("cls");
                        printf("[PROGRAM TERMINATED]");
                        doneViewing = 1;
                    }
                    else if (getUserChoiceToExitPage == 2)
                    {
                        doneViewing = 0;
                    }
                    else 
                    {
                        invalid();
                    }
            } while (getUserChoiceToExitPage != 2 && getUserChoiceToExitPage != 1);
                
        }
        else
        {
            invalid();
        }
         
        
    }
    
    return 0;
}