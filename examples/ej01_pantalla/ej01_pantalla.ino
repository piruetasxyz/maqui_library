/*
  Play Animation

  Sketch shows animation defined in animation.h

  See the full documentation here:
  https://docs.arduino.cc/tutorials/uno-r4-wifi/led-matrix
*/

//Include animation.h header file
#include "animation.h"            

// ex00_sequencer
// by montoyamoraga
// may 2024

// import library
# include "Maqui.h"

Maqui maqui;

// Create an instance of the ArduinoLEDMatrix class
// ArduinoLEDMatrix matrix;

void setup() {
  maqui.iniciar();
  // Serial.begin(115200);
  // you can also load frames at runtime, without stopping the refresh
  // matrix.loadSequence(animation);
  // matrix.begin();
  // turn on autoscroll to avoid calling next() to show the next frame; the paramenter is in milliseconds
  // matrix.autoscroll(300);
  // matrix.play(true);
}

void loop() {
  delay(500);
  Serial.println(millis());
}
