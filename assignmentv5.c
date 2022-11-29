/***********************************************************************
/* assignmentv5.c
/* Handle assessment marks for a course module
/* Wei Jie Guo
/* Version 5
***********************************************************************/ 

#include <stdio.h>
 
//function prototypes
int nameAmount();
int menu();
void supervisor();
void pause();
void fancyLines();
void emptyBuffer();
void displayMarks(int numName, char name[75][30], int crswk1[75], 
                int crswk2[75], int crswk3[75]);
char yesNo();
void enterMarks(int numName, char name[75][30], int crswk1[75], 
                int crswk2[75], int crswk3[75]);
void coursework1(int numName, char name[75][30], int crswk1[75]);
void coursework2(int numName, char name[75][30], int crswk2[75]);
void coursework3(int numName, char name[75][30], int crswk3[75]);

/*temporarily, [NAMES]/numNames will be 10. Need to change to 75 at
the end*/

int main()
{
    int crswk1[75] = {0};
    int crswk2[75] = {0};
    int crswk3[75] = {0};

    int numNames = nameAmount();
    char names[numNames][30];
 
    for(int i =0; i<numNames; i++)
    {
        printf("Enter the student in index %d: ", i);
        scanf("%s", names[i]);
        //%[^\n]%*c
    }
 
    printf("\n");
 
    for(int l = 0; l<numNames; l++) //error check
    {
        printf("in the index %d, student \"%s\" is stored\n"
        , l, names[l]);
    }

    int n = 1;
    while(n == 1)
    {
        int option;
        option = menu();

        if (option == 1)
        {
            //printf("%s", "testing testing\n"); //error check
            enterMarks(numNames, names, crswk1, crswk2, crswk3);
            yesNo();
        // call enter marks function
        }
        else if (option == 2)
        {
            
            printf("Display marks\n");
            //function - show student marks
            displayMarks(numNames, names, crswk1, crswk2, crswk3);
        }
        else if (option == 3)
        {
            //supervisor mode
            supervisor();
        }
        else if (option == 4)
        {
            printf("Closing program");
            return 0;
        }
        else
        {
            printf("I can't accept this option");
        }
        emptyBuffer();
    }
    return 0;
}

//supervisor mode
void supervisor()
{
    printf("\n\nYou are in supervisor mode\nInput your pin: ");
}

//Displays student marks
void displayMarks(int numName, char name[75][30], int crswk1[75], 
                int crswk2[75], int crswk3[75])
{
    int index1;
    printf("\nList of students: \n");
    for(int i = 0; i<numName; i++)
    {
        printf("Index %d is storing the marks for %s\n", i, name[i]);
    }
    printf("\nInput the student mark you would like to see"
            "\nEnter a number (0-74):  ");
    scanf("%d", &index1);
    printf("Student %s in the index %d: \nCoursework 1:%d     \n"
    "Coursework 2:%d    \nCoursework 3:%d\n\n", name[index1], index1, 
    crswk1[index1], crswk2[index1], crswk3[index1]);
    printf("The overall grades for this student is %g", 
    (crswk1[index1]*0.2)+(crswk2[index1]*0.3)+(crswk3[index1]*0.5));
}

//Allows the user to edit the marks they had input
char yesNo()
{
    char choice;
    printf("\n\nWould you like to edit anything?"
            "\nInput \"y\" or \"n\":  ");
    //fflush(stdin);
    emptyBuffer();
    
    while(choice == 'y'||choice == 'Y'||choice == 'n'||choice == 'N')
    {
        scanf("%c", &choice);
        printf("\nYou have entered: %c\n\n", choice);
        
        if(choice == 'y'||choice == 'Y')
        {
            printf("You would like to edit your marks"); //error check
            return 0;
        }
        else if(choice == 'n'||choice == 'N')
        {
            //error check
            printf("You would not like to edit your marks");
            return 0;
        }
        else
        {
            printf("Please select a valid option.");
        }
    }
}

//The menu prompt
int menu()
{
    int menu;
    printf("\n\n");
    fancyLines();
    printf("\nPick one of the menu options\n\n1. Enter marks\n"
        "2. Display a particular student's marks\n"
        "3. Supervisor mode\n4. Exit program\n");
    fancyLines();
    printf("\n\n\nEnter an option from 1 to 4:  ");
 
    while(menu<1 || menu > 4)
    {
        //emptyBuffer();
		fflush(stdin);
        scanf("%d", &menu);
 
        if(menu == 1)
        {
            printf("\nYou have chosen the first option: Enter marks\n");
        }
        else if(menu == 2)
        {
            printf("\nYou have chosen the second option: To display a "
            "student's marks\n");
        }
        else if(menu == 3)
        {
            printf("\nYou have chosen the third option: Supervisor "
            "mode\n");
        }
        else if(menu == 4)
        {
            printf("\nYou have chosen the fourth option: Exit "
            "program\n");
        }
        else
        {
            printf("\nI can't accept this option\n\n");
        }
    }
    return menu;
}

//Coursework 1 marks
void coursework1(int numName, char name[75][30], int crswk1[75])
{
    printf("You can now enter marks for coursework 1\n\n");
 
    for(int i = 0; i < numName; i++)
    {
        printf("Enter marks for students %s:  ", name[i]);
        scanf("%d", &crswk1[i]);
    }
    
    for(int i = 0; i < numName; i++) //error check
    {
        printf("\nStudent \"%s\" has %d marks  ", name[i], crswk1[i]);
    }
}

//Coursework 2 marks
void coursework2(int numName, char name[75][30], int crswk2[75])
{
    //coursework 2
    printf("You can now enter marks for coursework 2\n\n");
 
    for(int i = 0; i < numName; i++)
    {
        printf("Enter marks for students %s:  ", name[i]);
        scanf("%d", &crswk2[i]);
    }
    
    for(int i = 0; i < numName; i++) //error check
    {
        printf("\nStudent \"%s\" has %d marks  ", name[i], crswk2[i]);
    }
}

//Coursework 3 marks
void coursework3(int numName, char name[75][30], int crswk3[75])
{
    //coursework 3
    printf("You can now enter marks for coursework 3\n\n");
 
    for(int i = 0; i < numName; i++)
    {
        printf("Enter marks for students %s:  ", name[i]);
        scanf("%d", &crswk3[i]);
    }
    
    for(int i = 0; i < numName; i++) //error check
    {
        printf("\n");
        printf("Student \"%s\" has %d marks  ", name[i], crswk3[i]);
    }
}

//Allows the user to enter marks
void enterMarks(int numName,char name[75][30], int crswk1[75], int crswk2[75], int crswk3[75])
{
    int coursework = 0;
    printf("Do you want to enter marks for: \nCoursework 1\nCoursework "
    "2\nCoursework 3\n\n\"1\" = Coursework 1, \"2\" = Coursework "
    "2, \"3\" = Coursework 3:  ");
 
    while(coursework < 1 || coursework > 3)
    {
        //emptyBuffer();
        fflush(stdin);
        scanf("%d%*c", &coursework);
 
        if(coursework == 1)
        {
            //Error check
            printf("You have selected coursework 1\n\n");
            //will call function coursework1
            coursework1(numName, name, crswk1);
        }
        else if(coursework == 2)
        {
            //Error check
            printf("You have selected coursework 2\n\n");
            //will call function coursework2
            coursework2(numName, name, crswk2);
        }
        else if(coursework == 3)
        {
            //Error check
            printf("You have selected coursework 3\n\n");
            //will call function coursework3
            coursework3(numName, name, crswk3);
        }
        else
        {
            printf("I can't accept this option. Please enter a number "
            "between 1 and 3\n\n");
        }
    }
}

//Allows the user to input the amount of names they would like
int nameAmount()
{
    int numNames;
    printf("Input how many names you want to store: ");
    //emptyBuffer();
    fflush(stdin);
    scanf("%d", &numNames);
    //%[^\n]%*c
    printf("You are storing %d names\n\n", numNames); //error check
    return numNames;
}

void fancyLines()
{
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
}

void emptyBuffer()
{
	while(getchar() != '\n');
}
