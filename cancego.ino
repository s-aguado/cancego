
/*  cancego.ino
 *   
 *  Proxecto de colar para cans cegos ou con visibilidade reducida. 
 *  Consiste nun aviso sonoro que indica a proximidade dun obstáculo.
 *
 *  Sara Aguado Couselo © 2019
 */
 
#define NOSE /* Distancia do sensor ao fuciño (cm): */ 10
#define CONT /* Pitido continuo ata (cm):           */  5
#define FAST /* Pitido rápido ata (cm):             */ 10 
#define SLOW /* Pitido lento ata (cm):              */ 15

/*  AS CONSTANTES DEFINIDAS ENRIBA PERMITEN PERSONALIZAR O   */
/*  FUNCIONAMENTO DO COLAR SEGUNDO AS DISTINTAS NECESIDADES  */

 
#include <SR04.h>

const byte BUZZ_PIN =  8;
const byte ECHO_PIN = 11;
const byte TRIG_PIN = 12;

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance;

void setup() {
  pinMode(BUZZ_PIN, OUTPUT); // zumbador
}

void loop() {
  distance = sr04.Distance();                 // O sensor obtén a distancia en centímetros

  if (distance < NOSE || distance > SLOW) {   // Se a distancia é grande ou menor á do fuciño...
    noTone(BUZZ_PIN);                         // ...silencio para non molestar
  } 
  else if (distance < CONT) {                 // Se a distancia é PEQUENA...
    tone(BUZZ_PIN, 523);                      // ...o pitido é CONTINUO
  } 
  else if (distance < FAST) {
    tone(BUZZ_PIN, 523, 250);                 // Se a distancia é MEDIA...
    delay(325);                               // ...o pitido é RÁPIDO
    noTone(BUZZ_PIN);
  } 
  else if (distance < SLOW) {                 // Se a distancia é GRANDE...
    tone(BUZZ_PIN, 523, 250);                 // ...o pitido é LENTO
    delay(500);
    noTone(BUZZ_PIN);
  }

  /* A frecuencia de 523 Hz corresponde coa nota C5 */
}
