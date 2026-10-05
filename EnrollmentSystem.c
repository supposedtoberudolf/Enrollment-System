#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

typedef struct {
    char FullName[50];
    int Age;
    char Gender[10];
    char Nationality[15];
    char DateOfBirth[30];
    char ContactNumber[13];

    struct {
        char JuniorHighSchoolName[50];
        char JuniorAcademicYear[11];
        char SeniorHighSchoolName[50];
        char SeniorAcademicYear[11];
        double GWA;
    } Education;

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

void invalid() {

    printf("\n\nINVALID INPUT!");
    printf("\nPLEASE TRY AGAIN");
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

void Registration(Student student[10], int *studentCount, Program program[5], int *choice) {

    int valid[4] = {0};
    int editChoice = 0;

        system("cls");
        printf("\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("|                       REGISTRATION FORM                         |\n");
        printf("+-----------------------------------------------------------------+\n\n");
        printf("                    | STUDENT'S INFORMATION |                      \n\n");

        for (int i = 0; i < 8; i++)
        {
            printf("[%d] %-6s- %s \n", (i + 1), program[i].Code, program[i].Name);
            printf("-------------------------------------------------------------------\n");
        }
        printf("\nCHOOSE YOUR PROGRAM:  ");
        scanf("%d", choice);

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
        printf("+----------------------------------------------------------------------------------------+\n");
        printf("|                                REVIEW YOUR INFORMATION                                 |\n");
        printf("+----------------------------------------------------------------------------------------+\n\n");
        printf(" [1] PROGRAM        : %s - %s                                                \n", program[*choice - 1].Code, program[*choice - 1].Name);
        printf(" [2] FULL NAME      : %s                                                     \n", student[*studentCount].FullName);
        printf(" [3] AGE            : %d                                                     \n", student[*studentCount].Age);
        printf(" [4] NATIONALITY    : %s                                                     \n", student[*studentCount].Nationality);
        printf(" [5] DATE OF BIRTH  : %s                                                     \n", student[*studentCount].DateOfBirth);
        printf(" [6] CONTACT NUMBER : +63 %s                                                 \n\n", student[*studentCount].ContactNumber);
        printf("+----------------------------------------------------------------------------------------+\n");
        printf("\n [0] SUBMIT\n");
        printf("\n DO YOU WISH TO EDIT YOUR INFORMATION [CHOOSE FORM 1-6]: ");
        scanf("%d", &editChoice);

        system("cls");
        if (editChoice == 1)
        {
            for (int i = 0; i < 8; i++)
            {
                printf("[%d] %-6s- %s \n", (i + 1), program[i].Code, program[i].Name);
                printf("-------------------------------------------------------------------\n");
            }
            printf("\nCHOOSE YOUR PROGRAM: ");
            scanf("%d", choice);
            valid[0] = 0;
        }
        else if (editChoice == 2)
        {
            getchar();
            printf("\nFULL NAME: ");
            fgets(student[*studentCount].FullName, sizeof(student[*studentCount].FullName), stdin);
            student[*studentCount].FullName[strcspn(student[*studentCount].FullName, "\n")] = '\0';
            valid[0] = 0;
        }
        else if (editChoice == 3)
        {
            printf("\nAGE: ");
            scanf("%d", &student[*studentCount].Age);
            valid[0] = 0;
        }
        else if (editChoice == 4)
        {
            getchar();
            printf("\nNATIONALITY: ");
            fgets(student[*studentCount].Nationality, sizeof(student[*studentCount].Nationality), stdin);
            student[*studentCount].Nationality[strcspn(student[*studentCount].Nationality, "\n")] = '\0';

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
            Sleep(3000);
            printf("\nSAVED CHANGES!\n");
            Sleep(3000);
            valid[0] = 1;
        }
        else
        {
            invalid();
            valid[0] = 0;
        }
          
    } while (valid[0] != 1);

        system("cls");
        printf("\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("|                       REGISTRATION FORM                         |\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("                     | EDUCATION BACKGROUND |                      \n\n");

        getchar();
        printf("\nPREVIOUS JUNIOR HIGH SCHOOL: ");
        fgets(student[*studentCount].Education.JuniorHighSchoolName, sizeof(student[*studentCount].Education.JuniorHighSchoolName), stdin);
        student[*studentCount].Education.JuniorHighSchoolName[strcspn(student[*studentCount].Education.JuniorHighSchoolName, "\n")] = '\0';

        printf("\nACADEMIC YEAR (JHS): ");
        fgets(student[*studentCount].Education.JuniorAcademicYear, sizeof(student[*studentCount].Education.JuniorAcademicYear), stdin);
        student[*studentCount].Education.JuniorAcademicYear[strcspn(student[*studentCount].Education.JuniorAcademicYear, "\n")] = '\0';

        printf("\nPREVIOUS SENIOR HIGH SCHOOL: ");
        fgets(student[*studentCount].Education.SeniorHighSchoolName, sizeof(student[*studentCount].Education.SeniorHighSchoolName), stdin);
        student[*studentCount].Education.SeniorHighSchoolName[strcspn(student[*studentCount].Education.SeniorHighSchoolName, "\n")] = '\0';

        printf("\nACADEMIC YEAR (SHS): ");
        fgets(student[*studentCount].Education.SeniorAcademicYear, sizeof(student[*studentCount].Education.SeniorAcademicYear), stdin);
        student[*studentCount].Education.SeniorAcademicYear[strcspn(student[*studentCount].Education.SeniorAcademicYear, "\n")] = '\0';

        printf("\nGENERAL WEIGHTED AVERAGE: ");
        scanf("%lf", &student[*studentCount].Education.GWA);

        do
        {
            system("cls");
            printf("\n");
            printf("+----------------------------------------------------------------------------------------+\n");
            printf("|                                REVIEW YOUR INFORMATION                                 |\n");
            printf("+----------------------------------------------------------------------------------------+\n\n");
            printf(" [1] PREVIOUS JUNIOR HIGH SCHOOL   : %s                    \n", student[*studentCount].Education.JuniorHighSchoolName);
            printf(" [2] ACADEMIC YEAR (JHS)           : %s                    \n", student[*studentCount].Education.JuniorAcademicYear);
            printf(" [3] PREVIOUS SENIOR HIGH SCHOOL   : %s                    \n", student[*studentCount].Education.SeniorHighSchoolName);
            printf(" [4] ACADEMIC YEAR (SHS)           : %s                    \n", student[*studentCount].Education.SeniorAcademicYear);
            printf(" [5] GENERAL WEIGHTED AVERAGE      : %.2lf                    \n\n", student[*studentCount].Education.GWA);
            printf("+----------------------------------------------------------------------------------------+\n");
            printf("\n [0] SUBMIT\n");
            printf("\n DO YOU WISH TO EDIT YOUR INFORMATION [CHOOSE FROM 1-5]: ");
            scanf("%d", &editChoice);

        system("cls");
        if (editChoice == 1)
        {
            getchar();
            printf("\nPREVIOUS JUNIOR HIGH SCHOOL: ");
            fgets(student[*studentCount].Education.JuniorHighSchoolName, sizeof(student[*studentCount].Education.JuniorHighSchoolName), stdin);
            student[*studentCount].Education.JuniorHighSchoolName[strcspn(student[*studentCount].Education.JuniorHighSchoolName, "\n")] = '\0';
            valid[1] = 0;
        }
        else if (editChoice == 2)
        {
            getchar();
            printf("\nACADEMIC YEAR (JHS): ");
            fgets(student[*studentCount].Education.JuniorAcademicYear, sizeof(student[*studentCount].Education.JuniorAcademicYear), stdin);
            student[*studentCount].Education.JuniorAcademicYear[strcspn(student[*studentCount].Education.JuniorAcademicYear, "\n")] = '\0';
            valid[1] = 0;
        }
        else if (editChoice == 3)
        {
            getchar();
            printf("\nPREVIOUS SENIOR HIGH SCHOOL: ");
            fgets(student[*studentCount].Education.SeniorHighSchoolName, sizeof(student[*studentCount].Education.SeniorHighSchoolName), stdin);
            student[*studentCount].Education.SeniorHighSchoolName[strcspn(student[*studentCount].Education.SeniorHighSchoolName, "\n")] = '\0';
            valid[1] = 0;
        }
        else if (editChoice == 4)
        {
            getchar();
            printf("\nACADEMIC YEAR (SHS): ");
            fgets(student[*studentCount].Education.SeniorAcademicYear, sizeof(student[*studentCount].Education.SeniorAcademicYear), stdin);
            student[*studentCount].Education.SeniorAcademicYear[strcspn(student[*studentCount].Education.SeniorAcademicYear, "\n")] = '\0';
            valid[1] = 0;
        }
        else if (editChoice == 5)
        {
            printf("\nGENERAL WEIGHTED AVERAGE: ");
            scanf("%lf", &student[*studentCount].Education.GWA);
            valid[1] = 0;
        }
        
        else if (editChoice == 0)
        {
            printf("\nPROCESSING . . . .\n");
            Sleep(3000);
            printf("\nSAVED CHANGES!\n");
            Sleep(3000);
            valid[1] = 1;
        }
        else
        {
            invalid();
            valid[1] = 0;
        }
        } while (valid[1] != 1);
        

        system("cls");
        printf("\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("|                       REGISTRATION FORM                         |\n");
        printf("+-----------------------------------------------------------------+\n\n");
        printf("                     | MOTHER'S INFORMATION |                      \n");

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
        printf("+----------------------------------------------------------------------------------------+\n");
        printf("|                                REVIEW YOUR INFORMATION                                 |\n");
        printf("+----------------------------------------------------------------------------------------+\n\n");
        printf(" [1] MOTHER'S FULL NAME       : %s                                  \n", student[*studentCount].MotherInfo.FullName);
        printf(" [2] OCCUPATION               : %s                                  \n", student[*studentCount].MotherInfo.Occupation);
        printf(" [3] CONTACT NUMBER           : %s                                  \n\n", student[*studentCount].MotherInfo.ContactNumber);
        printf("+----------------------------------------------------------------------------------------+\n");
        printf("\n [0] SUBMIT\n");
        printf("\n DO YOU WISH TO EDIT YOUR INFORMATION [CHOOSE FROM 1-3]: ");
        scanf("%d", &editChoice);

        system("cls");
        if (editChoice == 1)
        {
            getchar();
            printf("\nMOTHER'S FULL NAME: ");
            fgets(student[*studentCount].MotherInfo.FullName, sizeof(student[*studentCount].MotherInfo.FullName), stdin);
            student[*studentCount].MotherInfo.FullName[strcspn(student[*studentCount].MotherInfo.FullName, "\n")] = '\0';
            valid[2] = 0;
        }
        else if (editChoice == 2)
        {
            getchar();
            printf("\nOCCUPATION: ");
            fgets(student[*studentCount].MotherInfo.Occupation, sizeof(student[*studentCount].MotherInfo.Occupation), stdin);
            student[*studentCount].MotherInfo.Occupation[strcspn(student[*studentCount].MotherInfo.Occupation, "\n")] = '\0';
            valid[2] = 0;
        }
        else if (editChoice == 3)
        {
            getchar();
            printf("\nCONTACT NUMBER: +63 ");
            fgets(student[*studentCount].MotherInfo.ContactNumber, sizeof(student[*studentCount].MotherInfo.ContactNumber), stdin);
            student[*studentCount].MotherInfo.ContactNumber[strcspn(student[*studentCount].MotherInfo.ContactNumber, "\n")] = '\0';
            valid[2] = 0;
        }
        else if (editChoice == 0)
        {
            printf("\nPROCESSING . . . .\n");
            Sleep(3000);
            printf("\nSAVED CHANGES!\n");
            Sleep(3000);
            valid[2] = 1;
        }
        else
        {
            invalid();
            valid[2] = 0;
        }
          
    } while (valid[2] != 1);

        system("cls");
        printf("\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("|                       REGISTRATION FORM                         |\n");
        printf("+-----------------------------------------------------------------+\n\n");
        printf("                     | FATHER'S INFORMATION |                      \n");

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
        printf("+----------------------------------------------------------------------------------------+\n");
        printf("|                                REVIEW YOUR INFORMATION                                 |\n");
        printf("+----------------------------------------------------------------------------------------+\n\n");
        printf(" [1] FATHER'S FULL NAME       : %s                                  \n", student[*studentCount].FatherInfo.FullName);
        printf(" [2] OCCUPATION               : %s                                  \n", student[*studentCount].FatherInfo.Occupation);
        printf(" [3] CONTACT NUMBER           : %s                                  \n\n", student[*studentCount].FatherInfo.ContactNumber);
        printf("+----------------------------------------------------------------------------------------+\n");
        printf("\n [0] SUBMIT\n");
        printf("\n DO YOU WISH TO EDIT YOUR INFORMATION [CHOOSE FROM 1-3]: ");
        scanf("%d", &editChoice);

        system("cls");
        if (editChoice == 1)
        {
            getchar();
            printf("\nFATHER'S FULL NAME: ");
            fgets(student[*studentCount].FatherInfo.FullName, sizeof(student[*studentCount].FatherInfo.FullName), stdin);
            student[*studentCount].FatherInfo.FullName[strcspn(student[*studentCount].FatherInfo.FullName, "\n")] = '\0';
            valid[3] = 0;
        }
        else if (editChoice == 2)
        {
            getchar();
            printf("\nOCCUPATION: ");
            fgets(student[*studentCount].FatherInfo.Occupation, sizeof(student[*studentCount].FatherInfo.Occupation), stdin);
            student[*studentCount].FatherInfo.Occupation[strcspn(student[*studentCount].FatherInfo.Occupation, "\n")] = '\0';
            valid[3] = 0;
        }
        else if (editChoice == 3)
        {
            getchar();
            printf("\nCONTACT NUMBER: +63 ");
            fgets(student[*studentCount].FatherInfo.ContactNumber, sizeof(student[*studentCount].FatherInfo.ContactNumber), stdin);
            student[*studentCount].FatherInfo.ContactNumber[strcspn(student[*studentCount].FatherInfo.ContactNumber, "\n")] = '\0';
            valid[3] = 0;
        }
        else if (editChoice == 0)
        {
            printf("\nPROCESSING . . . .\n");
            Sleep(3000);
            printf("\nSAVED CHANGES!\n");
            Sleep(3000);
            valid[3] = 1;
        }
        else
        {
            invalid();
            valid[3] = 0;
        }
          
    } while (valid[3] != 1);

        system("cls");
        printf("\n");
        printf("+----------------------------------------------------------------------------------------+\n");
        printf("|                                STUDENT'S INFORMATION                                   |\n");
        printf("+----------------------------------------------------------------------------------------+\n\n");
        printf(" -> PROGRAM                      : %s - %s                             \n", program[*choice - 1].Code, program[*choice - 1].Name);
        printf(" -> FULL NAME                    : %s                                  \n", student[*studentCount].FullName);
        printf(" -> AGE                          : %d YEARS OLD                        \n", student[*studentCount].Age);
        printf(" -> NATIONALITY                  : %s                                  \n", student[*studentCount].Nationality);
        printf(" -> DATE OF BIRTH                : %s                                  \n", student[*studentCount].DateOfBirth);
        printf(" -> CONTACT NUMBER               : +63 %s                              \n\n", student[*studentCount].ContactNumber);
        printf("+----------------------------------------------------------------------------------------+\n\n");
        printf("+----------------------------------------------------------------------------------------+\n");
        printf("|                                EDUCATION BACKGROUND                                    |\n");
        printf("+----------------------------------------------------------------------------------------+\n\n");
        printf(" -> PREVIOUS JUNIOR HIGH SCHOOL  : %s                    \n", student[*studentCount].Education.JuniorHighSchoolName);
        printf(" -> ACADEMIC YEAR (JHS)          : %s                    \n", student[*studentCount].Education.JuniorAcademicYear);
        printf(" -> PREVIOUS SENIOR HIGH SCHOOL  : %s                    \n", student[*studentCount].Education.SeniorHighSchoolName);
        printf(" -> ACADEMIC YEAR (SHS)          : %s                    \n", student[*studentCount].Education.SeniorAcademicYear);
        printf(" -> GENERAL WEIGHTED AVERAGE     : %.2lf                    \n\n", student[*studentCount].Education.GWA);
        printf("+----------------------------------------------------------------------------------------+\n\n");
        printf("+----------------------------------------------------------------------------------------+\n");
        printf("|                                 MOTHER INFORMATION                                     |\n");
        printf("+----------------------------------------------------------------------------------------+\n\n");
        printf(" -> MOTHER'S FULL NAME           : %s                                  \n", student[*studentCount].MotherInfo.FullName);
        printf(" -> OCCUPATION                   : %s                                  \n", student[*studentCount].MotherInfo.Occupation);
        printf(" -> CONTACT NUMBER               : %s                                  \n\n", student[*studentCount].MotherInfo.ContactNumber);
        printf("+----------------------------------------------------------------------------------------+\n\n");
        printf("+----------------------------------------------------------------------------------------+\n");
        printf("|                                 FATHER INFORMATION                                     |\n");
        printf("+----------------------------------------------------------------------------------------+\n\n");
        printf(" -> FATHER'S FULL NAME           : %s                                  \n", student[*studentCount].FatherInfo.FullName);
        printf(" -> OCCUPATION                   : %s                                  \n", student[*studentCount].FatherInfo.Occupation);
        printf(" -> CONTACT NUMBER               : %s                                  \n\n", student[*studentCount].FatherInfo.ContactNumber);
        printf("+----------------------------------------------------------------------------------------+\n");
        printf("\n PRESS [ENTER] TO SUBMIT & FINISH REGISTRATION: ");
        getch();

        printf("\n\nPROCESSING . . . .");
        Sleep(5000);
        printf("\nCONGRATULATIONS! YOU'RE ENROLLED.\n");
        Sleep(3000);
        (*studentCount)++;

}

int main() {

    Program program[8] = {
        {
            "BACHELOR OF SCIENCE IN INFORMATION TECHNOLOGY",
            "BSIT",
            "COMPUTER STUDIES DEPARTMENT",
            150
        },
        {
            "BACHELOR OF SCIENCE IN INFORMATION TECHNOLOGY",
            "BSIS",
            "COMPUTER STUDIES DEPARTMENT",
            146
        },
        {
            "BACHELOR OF SCIENCE IN COMPUTER SCIENCE",
            "BSCS",
            "COMPUTER STUDIES DEPARTMENT",
            153
        },
        {
            "BACHELOR OF SCIENCE IN ENTERTAINMENT AND MULTIMEDIA COMPUTING",
            "BSEMC",
            "COMPUTER STUDIES DEPARTMENT",
            143
        },
        {
            "BACHELOR OF SCIENCE IN COMPUTER ENGINEERING",
            "BSCpE",
            "COLLEGE OF ENGINEERING",
            156
        },
        {
            "BACHELOR OF SCIENCE IN ELECTONICS ENGINEERING",
            "BSECE",
            "COLLEGE OF ENGINEERING",
            154
        },
        {
            "BACHELOR OF SCIENCE IN CHEMICAL ENGINEERING",
            "BSCHE",
            "COLLEGE OF ENGINEERING",
            157
        },
        {
            "BACHELOR OF SCIENCE IN MECHANICAL ENGINEERING",
            "BSME",
            "COLLEGE OF ENGINEERING",
            157
        }
        
    };

    Student student[10];
    int studentCount = 0;

    int userChoice = 0;

    int limit = 10;

    int getUserProgramChoice = 0;

    // FLAG VARIABLE

    char wishToReturn = '\0';
    int agreeToTerms = 0;

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
                    Registration(student, &studentCount, program, &getUserProgramChoice);
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

            for (int i = 0; i < 8; i++)
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