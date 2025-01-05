/*
File name: SDBAPP.c

File description: Source file that runs the database app function containing the super loop that keeps the app running
and the action function that executes the appropriate action based on the user choice

Author: Amir El-Din Salah

Created: Dec. 25th 2024 (25/12/2024) 12:51AM

Version: 1.0
*/
#include <stdio.h>
#include "STD.h"
#include "SDB.h"
void SDB_APP (){
while(1){
        printf("Please, Enter your choice:\n1. To add entry, enter 1\n2. To get used size in database, enter 2\n3. To read student data, enter 3\n4. To get the list of all student IDs, enter 4\n5. To check if ID is existed, enter 5\n6. To delete student data, enter 6\n7. To check is database is full, enter 7\n8. To exit enter 0\n");
        scanf(" %c",&choice);
        //printf("The choice is %c\n",choice);
        if(choice == '0'){printf("You have chosen to exit the database app!\n");break;}
        SDB_action (choice);
            /* the function SDB_APP() contains the super loop (a.k.a. infinite loop that runs the database application
            if the user chooses to exit the app the loop breaks and app ends.
            if he chooses any other choice, the choice is passed to the function SDB_action(uint8 action) to execute the user choice*/

            }
}


void SDB_action (uint8 choice){

    switch(choice)
    {
    /* a conditional switch that executes and calls functions based on the user choice */

    case '1':   printf("You have chosen to add a new entry to the database\n");
                if(SDB_AddEntry()){printf("Data has been entered successfully\n\n");}else{if(usedSize<DATABASE_SIZE){dataBase[usedSize].Student_ID=0;dataBase[usedSize].Student_year=0;dataBase[usedSize].Course1_ID=0;dataBase[usedSize].Course1_grade=0;dataBase[usedSize].Course2_ID=0;dataBase[usedSize].Course2_grade=0;dataBase[usedSize].Course3_ID=0;dataBase[usedSize].Course3_grade=0;}printf("There was an error entering the data. Please, Try again!\n\n");}
                /* in case the user enters '1' as a choice to add entry, a message is printed to confirm the choice and the function SDB_AddEntry() is called
                if the function returns true indicating that data is stored successfully. else, it clears the data that could be stored during the process and prints a message
                showing that data was not stored successfully */
                break;

    case '2':   printf("You have chosen to show you the used size in the database\n");
                printf("Your Database has used size for %d student(s)!\n\n",SDB_GetUsedSize());
                /* in case the user enters '2' as a choice to get used size in the database, a message is printed to confirm the choice and the function SDB_GetUsedSize() is called
                and the return in printed in a message to show the user the used size in the data base */
                break;

    case '3':   printf("You have chosen to read student's data from the database\n");
                printf("Please, Enter student's ID\n");
                scanf(" %d",&tempData);
                if(!SDB_ReadEntry(tempData)){printf("Sorry!, The ID you entered is not listed in the database!\n\n");};
                /* in case the user enters '3' as a choice to read student's data, a message is printed to confirm the choice and the user will be asked to enter the student's ID
                which will be scanned and stored in the variable tempData. Then, the function SDB_ReadEntry(uint32 id) will be called and the scanned ID will be passed to it.
                Since the function returns bool, if the function returns false (in case the entered ID is not listed in the data base the function will return 0) a message will be printed to
                indicate the problem */
                break;

    case '4':   printf("You have chosen to get list of IDs in the database\n");
                SDB_GetList (&count, &list[0]);
                if(count == 0){printf("Your database contains %d IDs for students\n\n",count);}
                else{printf("Your database contains %d IDs for students which are:\n",count);
                for(i=0;i<usedSize;i++){printf("ID number %d: %d\n",i+1,list[i]);}
                printf("\n");}
                /* in case the user enters '4' as a choice to get IDs list, a message is be printed confirming the choice
                and the function void SDB_GetList(uint8 * count, uint32 * list) will be called by passing variable "count" and array "list" by address to the function
                then, both the variable "count" and array "list" will be used to print the number and values of IDs to the user */
                break;

    case '5': printf("You have chosen to check if and ID exists in the database\n");
              printf("Please, Enter student's ID\n");
              scanf(" %d",&tempData);
              if(SDB_IsIdExist(tempData)){printf("Your entered id exists in the database\n\n");}else{printf("Sorry, ID not found!\n\n");}
              /* in case the user enters '5' as a choice to check whether an ID exists in database or not, a message is printed to confirm the choice and the user will be asked to enter
              the ID he desires to check upon. if the function returns 1 indicating that the ID exists a message will be printed to confirm. Otherwise,  message will be printed
              to show that the ID is not found */
              break;

    case '6': printf("You have chosen to delete a student from the database\n");
              printf("Please, Enter student's ID\n");
              scanf(" %d",&tempData);
              SDB_DeletEntry(tempData);
              /* in case the user enters '6' as a choice to delete a student from the database, a message is printed confirming the choice and the user will be
              asked to enter the student's ID which will be scanned in the variable tempData. Then, the function SDB_DeletEntry(uint32 id) will be called by passing
              the ID that was scanned from the user entry */
              break;

    case '7': printf("You have chosen to check if database if full\n");
              if(SDB_IsFull()){printf("Sorry! Your database is full!\n\n");}
              else{printf("Your database has %d free spaces\n\n",DATABASE_SIZE-usedSize);}
              /* in case the user enters '6' as a choice to check if database is full or not, a message is printed to confirm the choice and the function SDB_IsFull() is called.
              By checking on its return a message will be printed to show that the database is full if the function returns true. Otherwise, a message will be printed showing
              how many free spaces exist in the database */
              break;




    default: printf("Wrong Entry!\n\n");
             /* in default case, if the user enters anything other than the handled cases, a message is printed showing that it's a wrong entry */
    }

}
