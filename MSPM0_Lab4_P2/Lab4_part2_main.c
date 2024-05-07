//*****************************************************************************
//*****************************    C Source Code    ***************************
//*****************************************************************************
//
//  DESIGNER NAME:  Bruce Link
//
//       LAB NAME:  Lab 4, part 2
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
#include "ti/devices/msp/m0p/mspm0g350x.h"
#include "ti/devices/msp/peripherals/hw_gpio.h"
#include "uart.h"



//-----------------------------------------------------------------------------
// Define symbolic constants used by program
//-----------------------------------------------------------------------------
#define second 32000000
unsigned int test_reg16 = 0x0000;
unsigned int i;




//-----------------------------------------------------------------------------
// Define global variable and structures here.
// NOTE: when possible avoid using global variables
//-----------------------------------------------------------------------------

// Define a structure to hold different data types


int main(void)
{    
    GPIOA->GPRCM.RSTCTL = (GPIO_RSTCTL_KEY_UNLOCK_W | GPIO_RSTCTL_RESETSTKYCLR_CLR | GPIO_RSTCTL_RESETASSERT_ASSERT);
    GPIOB->GPRCM.RSTCTL = (GPIO_RSTCTL_KEY_UNLOCK_W | GPIO_RSTCTL_RESETSTKYCLR_CLR | GPIO_RSTCTL_RESETASSERT_ASSERT);
    GPIOA->GPRCM.PWREN  = (GPIO_PWREN_KEY_UNLOCK_W | GPIO_PWREN_ENABLE_ENABLE);
    GPIOB->GPRCM.PWREN  = (GPIO_PWREN_KEY_UNLOCK_W | GPIO_PWREN_ENABLE_ENABLE);
    clock_delay(24); // time for GPIO to power up

    // Configure LED1 PA0 as output
    IOMUX->SECCFG.PINCM[IOMUX_PINCM1] = IOMUX_PINCM_PC_MASK | IOMUX_PINCM1_PF_GPIOA_DIO00;
    
    // Configure LED2-R PB26 as output 
    IOMUX->SECCFG.PINCM[IOMUX_PINCM57] = IOMUX_PINCM_PC_MASK | IOMUX_PINCM57_PF_GPIOB_DIO26;
    
    // Configure LED2-G PB27 as output
    IOMUX->SECCFG.PINCM[IOMUX_PINCM58] = IOMUX_PINCM_PC_MASK | IOMUX_PINCM58_PF_GPIOB_DIO27;
    
    // Configure LED2-B PB22 as output
    IOMUX->SECCFG.PINCM[IOMUX_PINCM50] = IOMUX_PINCM_PC_MASK | IOMUX_PINCM50_PF_GPIOB_DIO22;

    // Enable data outputs for DIO31 to DIO0
    GPIOA->DOE31_0 |= GPIO_DOE31_0_DIO0_MASK;

    // Set and clear bit for LED1
    for(i = 0; i < 3; i++)
    {
        GPIOA->DOUT31_0 &= ~GPIO_DOE31_0_DIO0_MASK;
        clock_delay(second/4);
        GPIOA->DOUT31_0 |= GPIO_DOE31_0_DIO0_MASK;
        clock_delay(second/4);
    }

    clock_delay(second);

    // DOUTSET and DOUTCLR
    for(i = 0; i < 3; i++)
    {
        GPIOA->DOUTCLR31_0 = GPIO_DOE31_0_DIO0_MASK;
        clock_delay(second/4);
        GPIOA->DOUTSET31_0 = GPIO_DOE31_0_DIO0_MASK;
        clock_delay(second/4);
    }

    clock_delay(second);

    // DOUTTGL
    for(i = 0; i < 3; i++)
    {
        GPIOA->DOUTTGL31_0 = GPIO_DOE31_0_DIO0_MASK;
        clock_delay(second/4);
        GPIOA->DOUTTGL31_0 = GPIO_DOE31_0_DIO0_MASK;
        clock_delay(second/4);
    }
    
    clock_delay(second);


    // Enable data outputs for DIO26, DIO27, DIO22
    GPIOB->DOE31_0 |= GPIO_DOE31_0_DIO26_MASK;
    GPIOB->DOE31_0 |= GPIO_DOE31_0_DIO27_MASK;
    GPIOB->DOE31_0 |= GPIO_DOE31_0_DIO22_MASK;

    // Set and clear bit for all LEDs in LED2
    for(i = 0; i < 3; i++)
    {
        // R
        GPIOB->DOUT31_0 |= GPIO_DOE31_0_DIO26_MASK;
        clock_delay(second/4);
        GPIOB->DOUT31_0 &= ~GPIO_DOE31_0_DIO26_MASK;
        clock_delay(second/4);

        // G
        GPIOB->DOUT31_0 |= GPIO_DOE31_0_DIO27_MASK;
        clock_delay(second/4);
        GPIOB->DOUT31_0 &= ~GPIO_DOE31_0_DIO27_MASK;
        clock_delay(second/4);

        // B
        GPIOB->DOUT31_0 |= GPIO_DOE31_0_DIO22_MASK;
        clock_delay(second/4);
        GPIOB->DOUT31_0 &= ~GPIO_DOE31_0_DIO22_MASK;
        clock_delay(second/4);
    }

    clock_delay(second);

    // DOUTSET and DOUTCLR for RGB
    for(i = 0; i < 3; i++)
    {
        GPIOB->DOUTSET31_0 = GPIO_DOE31_0_DIO26_MASK;
        clock_delay(second/4);
        GPIOB->DOUTCLR31_0 = GPIO_DOE31_0_DIO26_MASK;
        clock_delay(second/4);
\

        GPIOB->DOUTSET31_0 = GPIO_DOE31_0_DIO27_MASK;
        clock_delay(second/4);
        GPIOB->DOUTCLR31_0 = GPIO_DOE31_0_DIO27_MASK;
        clock_delay(second/4);

        GPIOB->DOUTSET31_0 = GPIO_DOE31_0_DIO22_MASK;
        clock_delay(second/4);
        GPIOB->DOUTCLR31_0 = GPIO_DOE31_0_DIO22_MASK;
        clock_delay(second/4);
    }

    clock_delay(second);

    // DOUTTGL for RGB
    for(i = 0; i < 3; i++)
    {
        GPIOB->DOUTTGL31_0 = GPIO_DOE31_0_DIO26_MASK;
        clock_delay(second/4);
        GPIOB->DOUTTGL31_0 = GPIO_DOE31_0_DIO26_MASK;
        clock_delay(second/4);

        GPIOB->DOUTTGL31_0 = GPIO_DOE31_0_DIO27_MASK;
        clock_delay(second/4);
        GPIOB->DOUTTGL31_0 = GPIO_DOE31_0_DIO27_MASK;
        clock_delay(second/4);

        GPIOB->DOUTTGL31_0 = GPIO_DOE31_0_DIO22_MASK;
        clock_delay(second/4);
        GPIOB->DOUTTGL31_0 = GPIO_DOE31_0_DIO22_MASK;
        clock_delay(second/4);
    }

    for(;;);
} /* main */

