/*
    Autor:       Yael Ramirez
    Descripción: Encender un led con Raspberry 3B+ y biblioteca WiringPi (http://wiringpi.com/)
*/
#include <wiringPi.h>

#define LED  0 //GPIO 0, fisico 11. Usar comando "gpio readall" en la 
               //terminal de Raspberry para ver la configuracion de pines

int main() {
    wiringPiSetup(); //Configuracion inicail para los pines
    pinMode(LED, OUTPUT); //Ponemos el pin GPIO 0 en modo de salida
    while(1) { //Bucle infinito
        digitalWrite(LED, HIGH); //Encendemos LED
        delay(1000); //Esperamos 1 segundo
        digitalWrite(LED, LOW); //Apagamos LED
        delay(1000);
    return 0;
}
