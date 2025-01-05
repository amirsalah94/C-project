/*
File name: STD.h

File description: header file to declare new data types
based on old ones to be used in the student database C project

Author: Amir El-Din Salah

Created: Dec. 25th 2024 (25/12/2024) 12:51AM

Version: 1.0
*/

#ifndef STD_H_
#define STD_H_                   /* Header guard to protect this header file from being defined for several times */
typedef unsigned char uint8;     /* defining a new data type called "uint8" of type unsigned char */
typedef char int8;               /* defining a new data type called "int8" of type signed char */
typedef unsigned short uint16;   /* defining a new data type called "uint16" of type unsigned short int (2 Bytes size int) */
typedef short int16;             /* defining a new data type called "int16" of type signed short int (2 Bytes size int) */
typedef unsigned int uint32;     /* defining a new data type called "uint32" of type unsigned int (4 Bytes size int) */
typedef int int32;               /* defining a new data type called "int32" of type signed int (4 Bytes size int) */
typedef enum {false, true} bool; /* defining a new data "bool" a.k.a. boolean based on enum special data type*/
#endif // STD_H_
