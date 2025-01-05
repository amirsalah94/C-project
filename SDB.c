/*
File name: SDB.c

File description: source file containing declaration of all functions running processes and printing on the database which will be called
based on user choice in the function SDB_action(uint8 choice)

Author: Amir El-Din Salah

Created: Dec. 25th 2024 (25/12/2024) 12:51AM

Version: 1.0
*/
#include <stdio.h>
#include "STD.h"
#include "SDB.h"

bool SDB_IsFull (){
    /* A simple function that checks if the usedSize variable, which always counts the number of students stored in the database,
     is equal to or exceeds DATABASE_SIZE if true then the database is full and the function returns true
    else, the database has free space and returns false */
    if(usedSize>=DATABASE_SIZE){
        return true;
    }
    else{
    return false;
    }
}


uint8 SDB_GetUsedSize(){
    /* a function that is used to get the used size in the database so it's enough to return the variable usedSize that is always updated with the used
       size in the database */
    return usedSize;
}

bool SDB_AddEntry(){
    /* a function to add student's data to the database */
    if(usedSize>=DATABASE_SIZE){
    /* first, we need to check if the database is full or not.
    If it's full we return false because now we cannot add new students to the database */
            printf("Sorry, Your database is full!");
                return false;
                    }
    else{
            printf("Please, Enter the ID of the student you'd like to add!\n");
            scanf(" %d",&tempData);
            /* Since it was checked that there is free space in the database we start scanning data by scanning the ID first */
            if(!SDB_IsIdExist(tempData)){dataBase[usedSize].Student_ID=tempData;}else{printf("Sorry!, your ID already exists in the database!\n"); return false;}
            /* now we check if the ID doesn't exist in the database we start storing it. if it already exists we print a message and return false */
            printf("Please, Enter the year of the student you'd like to add!(from 1 to 12)\n");
            scanf(" %d",&tempData);
            /* scanning the year of the student */
            if(tempData>=1&&tempData<=12){dataBase[usedSize].Student_year=tempData;}else{printf("Sorry, Your entry for the year is wrong!\n");return false;}
            /* after checking if the year entry is between 1 to 12 as an example of 12 grades of school,
            the value is stored as a student year. if it's out of range it prints  message and returns false */
            printf("Please, Enter the ID of Course 1 you'd like to add!\n");
            scanf(" %d",&dataBase[usedSize].Course1_ID);
            /* scanning course 1 ID and storing it in the database */
            printf("Please, Enter the Grade of Course 1 you'd like to add!(from 0 to 100)\n");
            scanf(" %d",&tempData);
            /* here the user is asked to enter the grade of course 1 and the value is stored in tempData variable */
            if(tempData>=0&&tempData<=100){dataBase[usedSize].Course1_grade=tempData;}else{printf("Sorry, Your entry for the course 1 grade is wrong!\n");return false;}
            /* checking if the course 1 grade value is  between 0 and 100 it will be stored in the database else it will be print a message and return false */
            printf("Please, Enter the ID of Course 2 you'd like to add!\n");
            scanf(" %d",&dataBase[usedSize].Course2_ID);
            /* scanning course 2 ID and storing it in the database */
            printf("Please, Enter the Grade of Course 2 you'd like to add! (from 0 to 100)\n");
            scanf(" %d",&tempData);
            if(tempData>=0&&tempData<=100){dataBase[usedSize].Course2_grade=tempData;}else{printf("Sorry, Your entry for the course 2 grade is wrong!\n");return false;}
            /* checking if the course 2 grade value is  between 0 and 100 it will be stored in the database else it will be print a message and return false */
            printf("Please, Enter the ID of Course 3 you'd like to add!\n");
            scanf(" %d",&dataBase[usedSize].Course3_ID);
            /* scanning course 3 ID and storing it in the database */
            printf("Please, Enter the Grade of Course 3 you'd like to add! (from 0 to 100)\n");
            scanf(" %d",&tempData);
            if(tempData>=0&&tempData<=100){dataBase[usedSize].Course3_grade=tempData;}else{printf("Sorry, Your entry for the course 3 grade is wrong!\n");return false;}
            /* checking if the course 3 grade value is  between 0 and 100 it will be stored in the database else it will be print a message and return false */
            usedSize++; /* since all the data is stored correctly it increments the usedSize variable to match the number of students data stored in the database */
            printf("Your database now contains %d student(s).\n",usedSize); /* a print message to show the user how many students are stored in the database after the add entry process */
                    return true; /* it returns true since all data is stored successfully */
            }
        }


void SDB_DeletEntry (uint32 id){

if(SDB_IsIdExist(id)){ /* checking if the entered ID exists in the database */
        found = false; /* setting the found flag to false */
  for(i=0;i<usedSize-1;i++){ /* looping over the whole database starting from the first element within the used size as its useless to loop over the whole database */
    if(!found&&dataBase[i].Student_ID==id){
        found = true;
        /* Once the desired ID to be removed is found the flag is set to true */
    }
    if(found){
        temp = dataBase[i];
        dataBase[i]=dataBase[i+1];
        dataBase[i+1]=temp;
        /* for the rest of the loop after finding the student whose data is desired to be removed it will keep swapping this student element to the end of the array */
    }

  }
  if(dataBase[usedSize-1].Student_ID==id){
    dataBase[usedSize-1].Student_year=0;
    dataBase[usedSize-1].Student_ID=0;
    dataBase[usedSize-1].Course1_ID=0;
    dataBase[usedSize-1].Course1_grade=0;
    dataBase[usedSize-1].Course2_ID=0;
    dataBase[usedSize-1].Course2_grade=0;
    dataBase[usedSize-1].Course3_ID=0;
    dataBase[usedSize-1].Course3_grade=0;
    usedSize--;
    /* Double checking if the last element in the database array is the desired to be removed which is absolutely
    the one to be removed, His data are set to zero and the used size is decremented by one */
  }


}
else{
    printf("The ID you entered is not in the database!\n");
    /* if the entered ID doesn't exist in the database a message will printed to show that it doesn't exist */
}
}

bool SDB_ReadEntry (uint32 id){
        if(SDB_IsIdExist(id)){ /* Checking if the given ID exists in the database */
        for(i=0;i<usedSize;i++){
        if(dataBase[i].Student_ID==id){
        printf("The data of this student is:\nID: %d\nYear: %d\nCourse1 ID: %d\nCourse1 grade: %d\nCourse2 ID: %d\nCourse2 grade: %d\nCourse3 ID: %d\nCourse3 grade: %d\n\n",dataBase[i].Student_ID,dataBase[i].Student_year,dataBase[i].Course1_ID,dataBase[i].Course1_grade,dataBase[i].Course2_ID,dataBase[i].Course2_grade,dataBase[i].Course3_ID,dataBase[i].Course3_grade);
        return 1;
        /* looping over the stored data in the database and checking with the ID. Once the ID is found the student data is printed and function returns 1 */
            }
        }
    }
        return 0;
        /* if the given ID doesn't exist the function returns 0 */
}

void SDB_GetList (uint8 * count, uint32 * list){
    for(i=0;i<DATABASE_SIZE;i++){
        list[i]=0;
        /*First we loop over the list array that is passed by reference and clear all data inside considering if there was previous data stored in*/
    }
*count = usedSize; /* the number of IDs is equal to the usedSize in the database array so we can just assign it to the count variable that is passed by reference */
for(i=0;i<usedSize;i++){
    list[i]=dataBase[i].Student_ID;
    /* Now we loop within the database usedSize range and store the IDs one by one */
}
}

bool SDB_IsIdExist (uint32 id){

        for(i=0;i<usedSize;i++){
        if(dataBase[i].Student_ID==id){
        return 1;
        /* looping over the dataBase array within the usedSize and once the given ID is found it returns 1 */
            }
        }
        return 0;
        /* reaching this line means the ID is not found so it returns 0 */
}




