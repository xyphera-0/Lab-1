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
    // Add initializations of inputs and outputs
    P5DIR &= ~0x40; // P5.6
    P3DIR &= ~0x20; // Set P3.5
    P6DIR |= 0x03; // Set P6.0 and P6.1 (led)
    P4DIR |= 0x80; //P4.7
    P8DIR |= 0x01; //P8.0
    P3DIR |= 0x80; //P3.7
    P5DIR |= 0x10; //P5.4
    P4DIR |= 0x01; //P4.0
    P8DIR |= 0x20; //P8.5
    P3DIR |= 0x40; //P3.6
    P5DIR &= ~0x20; //P5.5
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
