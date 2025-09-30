#include <Arduino.h>
#include <FastLED.h>
#define MA_BROCHE_BOUTON 39
#define MA_BROCHE_ANGLE 32


CRGB monPixel;

#include <MicroOscSlip.h>
// Le nombre 128 entre les < > ci-dessous est le nombre maximal d'octets réservés pour les messages entrants.
// Les messages sortants sont écrits directement sur la sortie et ne nécessitent pas de réservation d'octets supplémentaires.
MicroOscSlip<128> monOsc(&Serial);


void setup() {

  
Serial.begin(115200);

pinMode( MA_BROCHE_BOUTON , INPUT );

FastLED.addLeds<WS2812, 27, GRB>(&monPixel, 1);

}

void loop() {
  int maLectureBouton = digitalRead( MA_BROCHE_BOUTON );
  int lectureAnalogique = analogRead(MA_BROCHE_ANGLE);
  // Serial.println(maLectureBouton);
  
  monOsc.sendInt("/bouton",maLectureBouton);
  monOsc.sendInt("/angle",lectureAnalogique);
  
  
  
  


if(lectureAnalogique < 1365) {

 monPixel = CRGB(0, 0, 255);
 FastLED.show();

}else if(lectureAnalogique >= 1365 && lectureAnalogique <= 2730 ){

 monPixel = CRGB(0, 255, 0);
 FastLED.show();

}
else{
  monPixel = CRGB(255, 0, 0);
  FastLED.show();
}

  delay(50);
}