//*****************************************************************************
//*****************************    C Source Code    ***************************
//*****************************************************************************
//
//  DESIGNER NAME:  Bruce Link
//
//       LAB NAME:  Lab 3, part 2
//
//      FILE NAME:  main.c
//
//-----------------------------------------------------------------------------
//
// DESCRIPTION:
//    This program serves as a practice exercise for students to implement 
//    bitwise operations in C. It includes a series of problems, each 
//    requiring the manipulation of bits in a test register using bitwise 
//    operations. The program initializes the UART communication, sets up 
//    the system clock, and provides a function 'msp_printf' to print 
//    messages over UART. 
//
//    Each problem is outlined with a description, and students are instructed 
//    to write code to solve the problem within the designated sections. 
//    Upon execution, the program demonstrates the effect of various 
//    bitwise operations on the test register, along with the corresponding 
//    output messages indicating the results of each operation. After 
//    completing all the problems, the program terminates.
//
//*****************************************************************************
//*****************************************************************************

//-----------------------------------------------------------------------------
// Loads standard C include files
//-----------------------------------------------------------------------------
#include <stdio.h>
//#include <string.h>

//-----------------------------------------------------------------------------
// Loads MSP launchpad board support macros and definitions
//-----------------------------------------------------------------------------
#include <ti/devices/msp/msp.h>
#include "Clock.h"
#include "uart.h"



//-----------------------------------------------------------------------------
// Define symbolic constants used by program
//-----------------------------------------------------------------------------

unsigned int test_reg16 = 0x0000;



//-----------------------------------------------------------------------------
// Define global variable and structures here.
// NOTE: when possible avoid using global variables
//-----------------------------------------------------------------------------

// Define a structure to hold different data types


int main(void)
{
 
  
  for(;;);

} /* main */

