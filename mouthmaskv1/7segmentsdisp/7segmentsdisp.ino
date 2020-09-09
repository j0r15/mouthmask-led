/*
	Fun Print all example

  This is a demonstration off a lot of the possibilities of the Fun superclass

	The circuit:
  * connect TM1637 pin CLK to Arduino pin D4
  * connect TM1637 pin DIO to Arduino pin D5
  * connect TM1637 pin Vcc to Arduino pin 5V
  * connect TM1637 pin GND to Arduino pin GND

	Created 25 September 2015
	By Bram Harmsen

	https://github.com/bremme/arduino-tm1637

*/

// include the SevenSegmentTM1637 library
#include "SevenSegmentTM1637.h"
#include "SevenSegmentExtended.h"
#include "SevenSegmentFun.h"

/* initialize global TM1637 Display object
*  The constructor takes two arguments, the number of the clock pin and the digital output pin:
* SevenSegmentTM1637(byte pinCLK, byte pinDIO);
*/
const byte PIN_CLK = D4;   // define CLK pin (any digital pin)
const byte PIN_DIO = D5;   // define DIO pin (any digital pin)
SevenSegmentFun    display(PIN_CLK, PIN_DIO);


// run setup code
void setup() {
  Serial.begin(9600);         // initializes the Serial connection @ 9600 baud
  display.begin();            // initializes the display
  display.setBacklight(100);  // set the brightness to 100 %
  delay(1000);                // wait 1000 ms
};

// run loop (forever)
void loop() {

  // // bouncing ball
  // unsigned int numMoves = 100; unsigned int timeDelay = 100;
  // display.bouncingBall(numMoves, timeDelay);
  //
  // // scrolling text
  // byte repeats = 2;
  //
  // // nightrider
  // repeats = 4;
  // display.nightrider(repeats);
  //
  // // snake
  // display.snake(repeats);

  // horizontal level (e.g equalizer)
  equalizer();
};


void equalizer() {
  // initialize horizontal level counters
    char i,j,k,l;
    byte levels[3];

    // repeat 5 times
    for ( byte r=0; r < 4; r++) {
      // increae i and k, decrease j and l
      for (i=0,j=100,k=0,l=100; i <= 100; i+=33, j-=33, k+=33, l-=33) {
          levels[0] = i; levels[1] = j; levels[2] = k; levels[3] = l;
          display.printLevelHorizontal(levels);
          delay(50);
      }
      // increae j and l, decrease i and k
      // for (i=100,j=0,k=100,l=0; i >= 0; i-=33, j+=33, k-=33, l+=33) {
      //     levels[0] = i; levels[1] = j; levels[2] = k; levels[3] = l;
      //     display.printLevelHorizontal(levels);
      //     delay(50);
      // }
    }
}
