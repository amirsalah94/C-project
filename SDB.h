/*
File name: SDB.h

File description: header file to declare new data type student, declare variables that
will be used in the database project and declare the prototype of the functions used
in the project

Author: Amir El-Din Salah

Created: Dec. 25th 2024 (25/12/2024) 12:51AM

Version: 1.0
*/


#include "STD.h"             /* including the STD.h header file as it defines the data types used in the simpleDb struct */
#ifndef SDB_H_               /* Header guard to protect this header file from being defined for several times */
#define SDB_H_
#define DATABASE_SIZE 10     /* defining the specified database size as an object like macro so that it becomes more readable in the code */

typedef struct SimpleDb
{
uint32 Student_ID;
uint32 Student_year;
uint32 Course1_ID;
uint32 Course1_grade;
uint32 Course2_ID;
uint32 Course2_grade;
uint32 Course3_ID;
uint32 Course3_grade;
} student;                                         /* defining a data type using special data type struct using the previously defined data type "uint32" (a.k.a. unsigned int)
                                                      and allocating it as a student data type */

student dataBase [DATABASE_SIZE];                  /* Declaring an array of type student, that was previously declared and allocated, that will be used as a database in this project*/
student temp;                                      /* Declaring a variable of type student, that was previously declared and allocated, which will be used to swap elements in the database in a step of deleting entry in the "void SDB_DeletEntry (uint32 id);" function*/
uint8 usedSize;                                    /* Declaring a variable of type uint8 (a.k.a. unsigned char) that will be used to count the number of students whose data is stored in the database and also refer to the location of the last student data stored in the database*/
uint8 choice;                                      /* Declaring a variable of type uint8 (a.k.a. unsigned char) to scan the choice of the user an pass it to the function "void SDB_action (uint8 choice);" */
uint16 i;                                          /* Declaring a variable of type uint16 (a.k.a unsigned short int) which will be used as a for loop counter in several functions */
uint32 tempData;                                   /* Declaring a variable of type uint32 (a.k.a. unsigned int) to scan data from user and use it in some operations in the code */
bool found;                                        /* Declaring a variable of type bool that was previously defined to be used in the "void SDB_DeletEntry(uint32 id);" function as a flag */
uint8 count;                                       /* Declaring a variable of type uint8 (a.k.a. unsigned char) to be passed by reference to function "void SDB_GetList(uint8 * count, uint32 * listo);" to get the number of IDs in the database */
uint32 list [DATABASE_SIZE];                       /* Declaring an array of type uint32 (a.k.a. unsigned int) to be passed by reference to function "void SDB_GetList(uint8 * count, uint32 * list);" to get the list of IDs in the database */
void SDB_action(uint8 choice);                     /* A prototype for the function "void SDB_action(uint8 choice){}"*/
void SDB_APP();                                    /* A prototype for the function "void SDB_APP(){}" */
bool SDB_IsFull();                                 /* A prototype for the function "bool SDB_IsFull(){}" */
uint8 SDB_GetUsedSize();                           /* A prototype for the function "uint8 SDB_GetUsedSize(){}" */
bool SDB_AddEntry();                               /* A prototype for the function "bool SDB_AddEntry(){}" */
void SDB_DeletEntry(uint32 id);                    /* A prototype for the function "void SDB_DeletEntry(uint32 id){}" */
bool SDB_ReadEntry(uint32 id);                     /* A prototype for the function "bool SDB_ReadEntry(uint32 id){}" */
void SDB_GetList(uint8 * count, uint32 * list);    /* A prototype for the function "void SDB_GetList(uint8 * count, uint32 * list){}" */
bool SDB_IsIdExist(uint32 id);                     /* A prototype for the function "bool SDB_IsIdExist(uint32 id){}" */
#endif // SDB_H_

