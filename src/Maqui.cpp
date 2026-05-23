#include "Maqui.h"
#include "Interfaz.h"
#include "Arduino.h"

int Maqui::canal = 1;
int Maqui::noteOn = 0x90;
int Maqui::noteOff = 0x80;
int Maqui::velocidadCero = 0x00;

Maqui::Maqui() {
    notas = new NotasMIDI();
    pantalla = new Pantalla12x8();
    perilla0 = new Perilla(patitaPerilla0);
    perilla1 = new Perilla(patitaPerilla1);
    perilla2 = new Perilla(patitaPerilla2);
}

Maqui::~Maqui() {
  if (notas != nullptr) {
    delete notas;
  }
  if (pantalla != nullptr) {
      delete pantalla;
  }
  if (perilla0 != nullptr) {
    delete perilla0;
  }
    if (perilla1 != nullptr) {
    delete perilla1;
  }
    if (perilla2 != nullptr) {
    delete perilla2;
  }
}

void Maqui::iniciar() {
  Serial1.begin(notas->velocidadSerial);
}

void Maqui::cambiarCanal(int nuevoCanal) {
  if (nuevoCanal < Maqui::canalMinimo || nuevoCanal > Maqui::canalMaximo) {
    // Error: canal fuera de rango
  } else {
  Maqui::canal = nuevoCanal;
  }
}

int Maqui::mostrarCanal() {
  return Maqui::canal;
}

void Maqui::enviarMIDINoteOn(int nota, int velocidad) {
  Serial1.write(noteOn);
  Serial1.write(nota);
  Serial1.write(velocidad);
}

void Maqui::enviarMIDINoteOff(int nota) {
  Serial1.write(noteOff);
  Serial1.write(nota);
  Serial1.write(velocidadCero);
}

void Maqui::enviarMIDIControlChange(int control, int valor) {
  Serial1.write(control);
  Serial1.write(valor);
}
