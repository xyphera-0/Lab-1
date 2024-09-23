////////////////////////////////////////////////////////////////////////
//** ENGR-2350 Template Project 
//** NAME: Xio Pelaez Cuacua & Gizelle Ojeda
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

uint8_t biLEDColor = 0; // 0: Off, 1: Green, 2: Red
uint8_t patternRunning = 0;

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
    P4DIR |= 0x00; //P4.7
    P8DIR |= 0x01; //P8.0
    P3DIR |= 0x80; //P3.7
    P5DIR |= 0x10; //P5.4
    P4DIR |= 0x01; //P4.0
    P8DIR |= 0x20; //P8.5
    P3DIR |= 0x40; //P3.6
    P5DIR |= 0x20; //P5.5
}

void TestIO() {
    // Add printf statement(s) for testing inputs
   // printf(P5IN & 0x40);
    //printf(P3IN & 0x20);
    printf("start");
    // Example code for testing outputs
    while(1){
        uint8_t cmd = getchar();
        if(cmd == 'a'){
            printf("a");
            // Turn LEDL On
            P8OUT |= 0x01;
        }else if(cmd == 'z'){
            printf("z");
            // Turn LEDL Off
            P8OUT &= ~0x01;
        }else if (cmd == 's'){
            printf("s");
            P8OUT |= 0x20;
        }else if (cmd == 'x'){
            printf("x");
            P8OUT &= ~0x20;
        }else if (cmd == 'q'){
            printf("q");
            P6OUT |= 0x01;
            P6OUT &= ~0x02;
        }else if (cmd == 'w'){
            printf("w");
            P6OUT |= 0x03;
        }else if (cmd == 'e'){
            printf("e");
            P6OUT |= 0x02;
            P6OUT &= ~0x01;
        }
    }
}

void ControlSystem() {
    if(P3IN & 0x20 != 0){ //the ss1 is on
        if(patternRunning != 0) { // has pattern started,
            if(status_Sequence != 100) { //is pattern complete, turn on green if no, they give code
                P6OUT |= 0x02;
                P6OUT &= ~0x01;
            }else if(status_Sequence == 100) {//is pattern complete, turn on red if yes, they give code
                P6OUT |= 0x01;
                P6OUT &= ~0x02;
                }
            }
        else if(patternRunning) { //pattern has not started, start pattern they give code
            uint8_t run_Sequence(void);
       }
    }
    else if(P3IN & 0x20 == 0) { //ss1 is off
        P6OUT |= 0x03;
        if(patternRunning != 0) { // BMPx pressed, yes
            if(P4IN & 0x01!= 0){ // everytime a button is pressed
                record_Segment(2);   // BMP0 P4.0 90 right
           }else if(P4IN & 0x04!= 0){
                record_Segment(1);   // BMP1 P4.2 45 right
           }else if(P4IN & 0x08!= 0){
                record_Segment(0);   // BMP2 P4.3 drive straight
           }else if(P4IN & 0x20!= 0){
                record_Segment(127); // BMP3 P4.5 stop for 1s
           }else if(P4IN & 0x40!= 0){
                record_Segment(1);  // BMP4 P4.6 45 left
           }else if(P4IN & 0x80!= 0){
                record_Segment(-2);  // BMP5 P4.7 90 left
           }
        }
            //if(){ //for every segment added, lights turn off or on
            //    P8OUT |= 0x01; //turns on
            //    P8OUT |= 0x20;
            //else if() {
            //    P8OUT &= ~0x01; //turns off
            //    P8OUT |= ~0x20;
            //    }

            patternRunning = 1;
            int8_t status_Segment(void);
            uint8_t run_Sequence(void);
    }
        else if(patternRunning != 0) { // BMPx pressed, no
            if(P5IN & 0x40 != 0) { //PB1 pressed, yes
                uint8_t pop_Segment(void); //remove last segment, give code
                patternRunning = 1;
                uint8_t run_Sequence(void);

                //wait for release

           }else if(P5IN & 0x40 == 0) { //PB1 pressed, no



        }
    }
    }

