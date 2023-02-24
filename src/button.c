/** @file button.c
 *
 * @brief Antirrebote de los botones.
 *
 * @par
 */

#include "button.h"
#include <Arduino.h>
// ====================================================================================================
// Private variables
// ====================================================================================================

static uint8_t estado_anterior = 0;
static uint8_t buttonState = 0;
static uint8_t lastButtonState = 0;

// ====================================================================================================
// Private functions
// ====================================================================================================

// ====================================================================================================
// Public function definitions
// ====================================================================================================
/*!
 * @brief Evaluar si el boton esta presionado o ya no
 *
 * @param[out] estado_anterior Variable para saber si se presiono o es falso.
 *
 * @return El estado del boton.
 */
uint8_t presionado(button_t *p_self)
{
    buttonState = digitalRead(p_self->pin);
    if (buttonState != lastButtonState)
    {

        if (buttonState == LOW)
        {
            estado_anterior = 1;
        }
        if (buttonState == HIGH)
        {
            estado_anterior = 0;
        }
    }
    lastButtonState = buttonState;
    return estado_anterior;
}

/*** end of file ***/
