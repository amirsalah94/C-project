/*
File name: main.c

File description: main source file that contains the main function

Author: Amir El-Din Salah

Created: Dec. 25th 2024 (25/12/2024) 12:51AM

Version: 1.0
*/
#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#include "SDB.h"

int main()
{

    SDB_APP ();
    /* in the main function, we just call the function SDB_APP() that executes the database application by running a super loop (a.k.a. infinite loop) */
    return 0;
    /* main function returns 0 indicating that the program is running successfully */
}
