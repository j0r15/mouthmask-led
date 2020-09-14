/*
	Created 25 September 2015
	By Bram Harmsen
	https://github.com/bremme/arduino-tm1637
*/

// include the SevenSegmentTM1637 library
#include "SevenSegmentTM1637.h"
#include "SevenSegmentExtended.h"
#include "SevenSegmentFun.h"

const byte PIN_CLK = D4;   // define CLK pin (any digital pin)
const byte PIN_DIO = D5;   // define DIO pin (any digital pin)
SevenSegmentFun    display(PIN_CLK, PIN_DIO);

#define ANALOG_PIN A0
#define ANALOG_THRESHOLD 512

// run setup code
void setup() {
  Serial.begin(9600);         // initializes the Serial connection @ 9600 baud
  display.begin();            // initializes the display
  display.setBacklight(100);  // set the brightness to 100 %
  delay(1000);                // wait 1000 ms
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
};


void loop() {
  Serial.println(analogRead(ANALOG_PIN));
  if(analogRead(ANALOG_PIN) > ANALOG_THRESHOLD) {
    equalizer();
  } else {
    display.clear();
  }
};


void equalizer() {
  // initialize horizontal level counters
    char i,j,k,l;
    byte levels[4];

      int speed = 100;
      /// random levels
      for (i=0,j=100,k=0,l=100; i <= 100; i+=33, j-=33, k+=33, l-=33) {
          levels[0] = k; levels[1] = j; levels[2] = k; levels[3] = l;
          display.printLevelHorizontal(levels);
          delay(speed);
          levels[0] = j; levels[1] = l; levels[2] = j; levels[3] = l;
          display.printLevelHorizontal(levels);
          delay(speed);
      }

      // // increae j and l, decrease i and k
      // for (i=100,j=0,k=100,l=0; i <= 100; i-=33, j+=33, k-=33, l+=33) {
      //     levels[0] = i; levels[1] = j; levels[2] = k; levels[3] = l;
      //     display.printLevelHorizontal(levels);
      //     delay(100);
      // }
      // for (i=0,j=100,k=0,l=100; i <= 100; i+=33, j-=33, k+=33, l-=33) {
      //     levels[0] = i; levels[1] = j; levels[2] = k; levels[3] = l;
      //     display.printLevelHorizontal(levels);
      //     delay(100);
      // }

}
