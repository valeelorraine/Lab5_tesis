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
int val = 0;                                       // Variable para el cambio de contadores
int FLAG;                                          // Flag de antirrebote

//*****************************************************************************************
//                                     S E T   U P 
//*****************************************************************************************
void setup() {
  init_contador_led(&contador1, 33, 25, 14, 12);   // Indicar pines conectados para los leds de cada contador  
  init_contador_led(&contador2, 33, 25, 14, 12);  
  boton_init(&boton1, 16);                         // Indicar pines conectados para los botones
  boton_init(&boton2, 17);
  boton_init(&boton3, 18);
}

//*****************************************************************************************
//                             P R I N C I P A L   L O O P 
//*****************************************************************************************
void loop(){
  if(presionado(&boton3) == 1){                        // Boton se presiona
    FLAG = 1;                                          // Antirrebote botón 3
    }
  else{                                                // Boton suelto
      if (FLAG == 1){
        val= !val;                                     // invertir valor del la variable switcheo;
        FLAG = 0;
    }
  }  

// Contador 1
  if(val == 1){
    contador_incrementar(&contador1, &boton1, &boton2);
    mostrar_contador(&contador1);
  }

// Contador 2
  else{
    contador_incrementar(&contador2, &boton1, &boton2);
    mostrar_contador(&contador2);
  }
}