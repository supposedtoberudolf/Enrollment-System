/*
    *ENROLLMENT SYSTEM*

    MGA GUSTO KO MANGYARE:
    1. MAGDISPLAY NG LANDING PAGE
    2. MAGKAROON NG THREE FUNCTIONS:
        1.) ENROLL
            - SELECT COURSE/PROGRAM
            - FILL UP BASIC INFORMATION
                - SHOULD AGREE TO TERMS AND CONDITIONS
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
#include <conio.h>
#include <windows.h>
#include <string.h>

typedef struct {
    char FullName[50];
    int Age;
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
    char department[50];
    int units;

}Program;

void WelcomePage() {

    printf("+-----------------------------------------------------------------+\n");
    printf("|                  --- UNIVERSITY OF KANKALOO ---                 |\n");
    printf("|               INNOVATION | VISION | INSPIRATION                 |\n");
    printf("+-----------------------------------------------------------------+\n");
    printf("|                 --- PRESS [ENTER] TO EXPLORE ---                |\n");
    printf("+-----------------------------------------------------------------+\n");
    while (getchar() != '\n');
    system("cls");
}

int displayDashboard() {

    int choice = 0;

    do
    {
        system("cls");
        printf("+-----------------------------------------------------------------+\n");
        printf("|                     UNIVERSITY OF KANKALOO                      |\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("|                    WELCOME TO OFFICIAL PAGE                     |\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("|                                                                 |\n");
        printf("|           [1] ENROLL                  [2] VIEW PROGRAMS         |\n");
        printf("|                                                                 |\n");
        printf("|           [3] ABOUT US                [4] EXIT                  |\n");
        printf("|                                                                 |\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("\n\nSELECT: ");
        scanf("%d", &choice);

    } while (choice > 4 || choice < 1);
    
    return choice;
    
}

void Terms_and_Conditions(int *select) {

    printf("\n");
    printf("+-----------------------------------------------------------------+\n");
    printf("|                      TERMS AND CONDITIONS                       |\n");
    printf("+-----------------------------------------------------------------+\n");
    printf("|                                                                 |\n");
    printf("|  1. ALL REQUIRED FIELDS MUST BE ANSWERED WITH ACCURATE INFO.    |\n");
    printf("|  2. PLEASE REVIEW YOUR DETAILS CAREFULLY BEFORE SUBMITTING.     |\n");
    printf("|  3. PROVIDING FALSE OR FRAUDULENT DATA MAY RESULT IN PENALTIES. |\n");
    printf("|  4. YOUR SUBMITTED DATA WILL BE HANDLED STRICTLY CONFIDENTIAL.  |\n");
    printf("|                                                                 |\n");
    printf("|                                                                 |\n");
    printf("+-----------------------------------------------------------------+\n");

    printf("\n\n[PRESS ENTER TO PROCEED]");
    getch();

    do
    {
        printf("\n\nDO YOU AGREE TO TERMS AND CONDITIONS? ");
        printf("\n[1] YES, I AGREE\n[2] NO, I DECLINE");

        printf("\n\nCHOOSE YOUR DECISION: ");
        scanf("%d", select);

    } while (*select != 1 && *select != 2);

}

void Registration(Student student[10], int *studentCount) {

    int valid[3] = {0};
    int editChoice = 0;

    
        system("cls");
        printf("\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("|                       REGISTRATION FORM                         |\n");
        printf("+-----------------------------------------------------------------+\n\n");
        printf("                    | STUDENT'S INFORMATION |                      \n");

        getchar();
        printf("\nFULL NAME: ");
        fgets(student[*studentCount].FullName, sizeof(student[*studentCount].FullName), stdin);
        student[*studentCount].FullName[strcspn(student[*studentCount].FullName, "\n")] = '\0';

        printf("\nAGE: ");
        scanf("%d", &student[*studentCount].Age);

        getchar();
        printf("\nNATIONALITY: ");
        fgets(student[*studentCount].Nationality, sizeof(student[*studentCount].Nationality), stdin);
        student[*studentCount].Nationality[strcspn(student[*studentCount].Nationality, "\n")] = '\0';

        printf("\nGENERAL WEIGHTED AVERAGE: ");
        scanf("%lf", &student[*studentCount].GWA);

        getchar();
        printf("\nDATE OF BIRTH(MM/DD/YY): ");
        fgets(student[*studentCount].DateOfBirth, sizeof(student[*studentCount].DateOfBirth), stdin);
        student[*studentCount].DateOfBirth[strcspn(student[*studentCount].DateOfBirth, "\n")] = '\0';

        printf("\nCONTACT NUMBER: +63 ");
        fgets(student[*studentCount].ContactNumber, sizeof(student[*studentCount].ContactNumber), stdin);
        student[*studentCount].ContactNumber[strcspn(student[*studentCount].ContactNumber, "\n")] = '\0';
        
        
    
    
    do
    {
        system("cls");
        printf("\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("|                    REVIEW YOUR INFORMATION                      |\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("[1] FULL NAME                : %s                                  \n", student[*studentCount].FullName);
        printf("[2] AGE                      : %d YEARS OLD                        \n", student[*studentCount].Age);
        printf("[3] NATIONALITY              : %s                                  \n", student[*studentCount].Nationality);
        printf("[4] GENERAL WEIGHTED AVERAGE : %.2lf                               \n", student[*studentCount].GWA);
        printf("[5] DATE OF BIRTH            : %s                                  \n", student[*studentCount].DateOfBirth);
        printf("[6] CONTACT NUMBER           : +63 %s                              \n", student[*studentCount].ContactNumber);
        printf("+-----------------------------------------------------------------+\n");
        printf("\n[0] SUBMIT & FINISH REGISTRATION\n");
        printf("\nDO YOU WISH TO EDIT YOUR INFORMATION[0-6]: ");
        scanf("%d", &editChoice);

        system("cls");
        if (editChoice == 1)
        {
            getchar();
            printf("\nFULL NAME: ");
            fgets(student[*studentCount].FullName, sizeof(student[*studentCount].FullName), stdin);
            student[*studentCount].FullName[strcspn(student[*studentCount].FullName, "\n")] = '\0';
            valid[0] = 0;
        }
        else if (editChoice == 2)
        {
            printf("\nAGE: ");
            scanf("%d", &student[*studentCount].Age);
            valid[0] = 0;
        }
        else if (editChoice == 3)
        {
            getchar();
            printf("\nNATIONALITY: ");
            fgets(student[*studentCount].Nationality, sizeof(student[*studentCount].Nationality), stdin);
            student[*studentCount].Nationality[strcspn(student[*studentCount].Nationality, "\n")] = '\0';

            valid[0] = 0;
        }
        else if (editChoice == 4)
        {
            printf("\nGENERAL WEIGHTED AVERAGE: ");
            scanf("%lf", &student[*studentCount].GWA);
            valid[0] = 0;
        }
        else if (editChoice == 5)
        {
            getchar();
            printf("\nDATE OF BIRTH(MM/DD/YY): ");
            fgets(student[*studentCount].DateOfBirth, sizeof(student[*studentCount].DateOfBirth), stdin);
            student[*studentCount].DateOfBirth[strcspn(student[*studentCount].DateOfBirth, "\n")] = '\0';

        }
        else if (editChoice == 6)
        {
            getchar();
            printf("\nCONTACT NUMBER: +63 ");
            fgets(student[*studentCount].ContactNumber, sizeof(student[*studentCount].ContactNumber), stdin);
            student[*studentCount].ContactNumber[strcspn(student[*studentCount].ContactNumber, "\n")] = '\0';
            valid[0] = 0;
        }
        else if (editChoice == 0)
        {
            printf("\nPROCESSING . . . .\n");
            valid[0] = 1;
        }
        else
        {
            valid[0] = 0;
        }
          
    } while (valid[0] != 1);

        system("cls");
        printf("\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("|                       REGISTRATION FORM                         |\n");
        printf("+-----------------------------------------------------------------+\n\n");
        printf("                | STUDENT'S MOTHER INFORMATION |                      \n");

        getchar();
        printf("\nMOTHER'S FULL NAME: ");
        fgets(student[*studentCount].MotherInfo.FullName, sizeof(student[*studentCount].MotherInfo.FullName), stdin);
        student[*studentCount].MotherInfo.FullName[strcspn(student[*studentCount].MotherInfo.FullName, "\n")] = '\0';

        printf("\nOCCUPATION: ");
        fgets(student[*studentCount].MotherInfo.Occupation, sizeof(student[*studentCount].MotherInfo.Occupation), stdin);
        student[*studentCount].MotherInfo.Occupation[strcspn(student[*studentCount].MotherInfo.Occupation, "\n")] = '\0';

        printf("\nCONTACT NUMBER: +63 ");
        fgets(student[*studentCount].MotherInfo.ContactNumber, sizeof(student[*studentCount].MotherInfo.ContactNumber), stdin);
        student[*studentCount].MotherInfo.ContactNumber[strcspn(student[*studentCount].MotherInfo.ContactNumber, "\n")] = '\0';

    do
    {
        system("cls");
        printf("\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("|                    REVIEW YOUR INFORMATION                      |\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("[1] MOTHER'S FULL NAME       : %s                                  \n", student[*studentCount].MotherInfo.FullName);
        printf("[2] OCCUPATION               : %s                                  \n", student[*studentCount].MotherInfo.Occupation);
        printf("[3] CONTACT NUMBER           : %s                                  \n", student[*studentCount].MotherInfo.ContactNumber);
        printf("+-----------------------------------------------------------------+\n");
        printf("\n[0] SUBMIT & FINISH REGISTRATION\n");
        printf("\nDO YOU WISH TO EDIT YOUR INFORMATION[0-3]: ");
        scanf("%d", &editChoice);

        system("cls");
        if (editChoice == 1)
        {
            getchar();
            printf("\nMOTHER'S FULL NAME: ");
            fgets(student[*studentCount].MotherInfo.FullName, sizeof(student[*studentCount].MotherInfo.FullName), stdin);
            student[*studentCount].MotherInfo.FullName[strcspn(student[*studentCount].MotherInfo.FullName, "\n")] = '\0';
            valid[1] = 0;
        }
        else if (editChoice == 2)
        {
            getchar();
            printf("\nOCCUPATION: ");
            fgets(student[*studentCount].MotherInfo.Occupation, sizeof(student[*studentCount].MotherInfo.Occupation), stdin);
            student[*studentCount].MotherInfo.Occupation[strcspn(student[*studentCount].MotherInfo.Occupation, "\n")] = '\0';
            valid[1] = 0;
        }
        else if (editChoice == 3)
        {
            getchar();
            printf("\nCONTACT NUMBER: +63 ");
            fgets(student[*studentCount].MotherInfo.ContactNumber, sizeof(student[*studentCount].MotherInfo.ContactNumber), stdin);
            student[*studentCount].MotherInfo.ContactNumber[strcspn(student[*studentCount].MotherInfo.ContactNumber, "\n")] = '\0';
            valid[1] = 0;
        }
        else if (editChoice == 0)
        {
            printf("\nPROCESSING . . . .\n");
            valid[1] = 1;
        }
        else
        {
            valid[1] = 0;
        }
          
    } while (valid[1] != 1);

        system("cls");
        printf("\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("|                       REGISTRATION FORM                         |\n");
        printf("+-----------------------------------------------------------------+\n\n");
        printf("                | STUDENT'S FATHER INFORMATION |                      \n");

        getchar();
        printf("\nFATHER'S FULL NAME: ");
        fgets(student[*studentCount].FatherInfo.FullName, sizeof(student[*studentCount].FatherInfo.FullName), stdin);
        student[*studentCount].FatherInfo.FullName[strcspn(student[*studentCount].FatherInfo.FullName, "\n")] = '\0';

        printf("\nOCCUPATION: ");
        fgets(student[*studentCount].FatherInfo.Occupation, sizeof(student[*studentCount].FatherInfo.Occupation), stdin);
        student[*studentCount].FatherInfo.Occupation[strcspn(student[*studentCount].FatherInfo.Occupation, "\n")] = '\0';

        printf("\nCONTACT NUMBER: +63 ");
        fgets(student[*studentCount].FatherInfo.ContactNumber, sizeof(student[*studentCount].FatherInfo.ContactNumber), stdin);
        student[*studentCount].FatherInfo.ContactNumber[strcspn(student[*studentCount].FatherInfo.ContactNumber, "\n")] = '\0';

    do
    {
        system("cls");
        printf("\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("|                    REVIEW YOUR INFORMATION                      |\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("[1] MOTHER'S FULL NAME       : %s                                  \n", student[*studentCount].FatherInfo.FullName);
        printf("[2] OCCUPATION               : %s                                  \n", student[*studentCount].FatherInfo.Occupation);
        printf("[3] CONTACT NUMBER           : %s                                  \n", student[*studentCount].FatherInfo.ContactNumber);
        printf("+-----------------------------------------------------------------+\n");
        printf("\n[0] SUBMIT & FINISH REGISTRATION\n");
        printf("\nDO YOU WISH TO EDIT YOUR INFORMATION[0-3]: ");
        scanf("%d", &editChoice);

        system("cls");
        if (editChoice == 1)
        {
            getchar();
            printf("\nFATHER'S FULL NAME: ");
            fgets(student[*studentCount].FatherInfo.FullName, sizeof(student[*studentCount].FatherInfo.FullName), stdin);
            student[*studentCount].FatherInfo.FullName[strcspn(student[*studentCount].FatherInfo.FullName, "\n")] = '\0';
            valid[2] = 0;
        }
        else if (editChoice == 2)
        {
            getchar();
            printf("\nOCCUPATION: ");
            fgets(student[*studentCount].FatherInfo.Occupation, sizeof(student[*studentCount].FatherInfo.Occupation), stdin);
            student[*studentCount].FatherInfo.Occupation[strcspn(student[*studentCount].FatherInfo.Occupation, "\n")] = '\0';
            valid[2] = 0;
        }
        else if (editChoice == 3)
        {
            getchar();
            printf("\nCONTACT NUMBER: +63 ");
            fgets(student[*studentCount].FatherInfo.ContactNumber, sizeof(student[*studentCount].FatherInfo.ContactNumber), stdin);
            student[*studentCount].FatherInfo.ContactNumber[strcspn(student[*studentCount].FatherInfo.ContactNumber, "\n")] = '\0';
            valid[2] = 0;
        }
        else if (editChoice == 0)
        {
            printf("\nPROCESSING . . . .\n");
            valid[2] = 1;
        }
        else
        {
            valid[2] = 0;
        }
          
    } while (valid[2] != 1);
    (*studentCount)++;

}

void invalid() {

    printf("\nINVALID INPUT!");
    printf("\nPLEASE TRY AGAIN");
}


int main() {

    Program program[5] = {
        {
            "Bachelor of Science in Information Technology",
            "BSIT",
            "Computer Studies Department",
            150
        },
        {
            "Bachelor of Science in Information System",
            "BSIS",
            "Computer Studies Department",
            146
        },
        {
            "Bachelor of Science in Computer Science",
            "BSCS",
            "Computer Studies Department",
            153
        },
        {
            "Bachelor of Science in Entertainment and Multimedia Computing",
            "BSEMC",
            "Computer Studies Department",
            143
        },
        {
            "Bachelor of Science in Computer Engineering",
            "BSCpE",
            "Computer Studies Department",
            156
        }
    };


    Student student[10];
    int studentCount = 0;
    int userChoice = 0;
    int limit = 10;

    int agreeToTerms = 0;

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
            if (studentCount != limit)
            {
                Terms_and_Conditions(&agreeToTerms);

                if (agreeToTerms == 1)
                {
                    Registration(student, &studentCount);

                }
                else
                {
                    printf("\nPROCESS CANCELED, YOU MUST AGREE TO PROCEED\n\n");
                    doneViewing = 0;
                }
            }
            else
            {
                printf("\nSORRY, STUDENT SLOTS ARE NOW FULL\n\n");
            }
            
        }
        else if (userChoice == 2)
        {
            printf("+-----------------------------------------------------------------+\n");
            printf("|                         PROGRAM OFFERED                         |\n");
            printf("+-----------------------------------------------------------------+\n");

            for (int i = 0; i < 5; i++)
            {
                printf("\nPROGRAM\t    : %-70s", program[i].Name);
                printf("\nCODE\t    : %-70s", program[i].Code);
                printf("\nDEPARTMENT  : %-70s", program[i].department);
                printf("\nUNITS\t    : %-70d", program[i].units);
                printf("\n\n+-----------------------------------------------------------------+\n");

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
                        system("cls");
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