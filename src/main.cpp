// Oscar Fuentes
// Valerie Valdez
// Universidad del Valle de Guatemala

//                            Diseño e innovación de ingeniería 
//                                      Labortorio 5


//*****************************************************************************************
//                                 L I B R E R Í A S  
//*****************************************************************************************
#include <Arduino.h>
#include "counter.h"
#include "button.h"

//*****************************************************************************************
//                                 V A R I A B L E S 
//*****************************************************************************************
contadorled_t contador1;
contadorled_t contador2;
button_t boton1;
button_t boton2;
button_t boton3;
bool flag1; 
bool flag2;
int val2;

//*****************************************************************************************
//                                     S E T   U P 
//*****************************************************************************************
void setup() {

  init_contador_led(&contador1, 33, 25, 14, 12);   // Indicar pines conectados para los leds  
  init_contador_led(&contador2, 33, 25, 14, 12);   // Indicar pines conectados para los leds  
  boton_init(&boton1, 16);                         // Indicar pines conectados para los botones
  boton_init(&boton2, 17);
  boton_init(&boton3, 18);
}

//*****************************************************************************************
//                             P R I N C I P A L   L O O P 
//*****************************************************************************************
void loop() {
  if((presionado(&boton3))){
    digitalWrite(25, HIGH);                        // encender led2
    delay(1000);
  }
  if((presionado(&boton2))){
    digitalWrite(25, LOW);                        // encender led2
    delay(1000);
  }
}
