// ex00_sequencer
// by montoyamoraga
// may 2024

// import library
# include "Maqui.h"

Maqui maqui;

int timeNoteOn = 300;
int timeNoteOff = 50;

void setup() {
  maqui.iniciar();
}

void loop() {

  for (int nota = 0x50; nota < 0x80; nota++) {

    maqui.enviarMIDINoteOn(nota, 0x64);
    delay(timeNoteOn);

    maqui.enviarMIDINoteOff(nota);
    delay(timeNoteOff);
  }
}