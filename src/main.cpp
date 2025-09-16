#include <Arduino.h>
#include <MicroOscSlip.h>
#include <FastLED.h>
// Le nombre 128 entre les < > ci-dessous est le nombre maximal d'octets réservés pour les messages entrants.
// Les messages sortants sont écrits directement sur la sortie et ne nécessitent pas de réservation d'octets supplémentaires.
MicroOscSlip<128> monOsc(&Serial);


#define MA_BROCHE_BOUTON 39
#define MA_BROCHE_ANGLE 32


CRGB monPixel;

void setup() {
  Serial.begin(115200);
  pinMode( MA_BROCHE_BOUTON , INPUT );
  FastLED.addLeds<WS2812, 27, GRB>(&monPixel, 1);

}

void loop() {
  int maLectureBouton = digitalRead( MA_BROCHE_BOUTON );
  int lectureAnalogique = analogRead(MA_BROCHE_ANGLE);

  
monOsc.sendInt( "/bouton" , maLectureBouton);
monOsc.sendInt( "/angle" , lectureAnalogique);

monPixel = CRGB(0, (millis()%255), 0);
FastLED.show();

delay(100);
}