////////////////////////////////////////////////////////////////////////
//** ENGR-2350 Template Project 
//** NAME: Xio Pelaez Cuacua
//** RIN: 662068537
//** This is the base project for several activities and labs throughout
//** the course.  The outline provided below isn't necessarily *required*
//** by a C program; however, this format is required within ENGR-2350
//** to ease debugging/grading by the staff.
////////////////////////////////////////////////////////////////////////

#include "engr2350_msp432.h"
#include "lab1lib.h"

void GPIOInit();
void TestIO();
void ControlSystem();

uint8_t LEDFL = 0; // Two variables to store the state of
uint8_t LEDFR = 0; // the front left/right LEDs (on-car)

int main(void) {    /** Main Function ****/

    SysInit(); // Basic car initialization
    init_Sequence(); // Initializes the Lab1Lib Driver
    GPIOInit();

    printf("\r\n\n"
           "===========\r\n"
           "Lab 1 Start\r\n"
           "===========\r\n");

    while(1) {
        TestIO(); // Used in Part A to test the IO
        //ControlSystem(); // Used in Part B to implement the desired functionality
    }
}    /** End Main Function ****/

void GPIOInit() {
    P6DIR = 0x// Add initializations of inputs and outputs
}

void TestIO() {
    // Add printf statement(s) for testing inputs

    // Example code for testing outputs
    while(1){
        uint8_t cmd = getchar();
        if(cmd == 'a'){
            // Turn LEDL On
        }else if(cmd == 'z'){
            // Turn LEDL Off
        }// ...
    }
}

void ControlSystem() {

}
