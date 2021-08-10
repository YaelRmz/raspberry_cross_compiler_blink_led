#include <wiringPi.h>
#include <stdio.h>
#include <sys/time.h>

#define LED1  0 //GPIO 0, fisico 11. Usar comando "gpio readall" en la 
               //terminal de Raspberry para ver la configuracion de pines
#define LED2  2 //GPIO 2, fisico 13 
#define LED3  3 //GPIO 3, fisico 15 
#define LED4  4 //GPIO 4, fisico 16 

void secuencia_exclusiva(int leds[4]);
void secuencia_aditiva(int leds[4]);

struct timeval stop, start;

int main() {
    gettimeofday(&start, NULL);
    wiringPiSetup(); //Configuracion inicail para los pines
    pinMode(LED1, OUTPUT); //Ponemos los pines GPIO en modo de salida
    pinMode(LED2, OUTPUT); 
    pinMode(LED3, OUTPUT); 
    pinMode(LED4, OUTPUT); 

    int leds_status[4] = {0, 0, 0, 0};
    int leds_pin[4] = {LED1, LED2, LED3, LED4};

    while(0) { //Bucle infinito
    }
    secuencia_exclusiva(leds_pin);
    delay(1000);
    secuencia_aditiva(leds_pin);
    delay(1000);
    gettimeofday(&stop, NULL);
    printf("took %lu us\n", (stop.tv_sec * 1000 + stop.tv_usec) - (start.tv_sec * 1000 + start.tv_usec));
    return 0;
}

void secuencia_exclusiva(int leds[4]) {
    int j;
    for(j = 0; j < 4; j++){
        digitalWrite(leds[j], HIGH); //Encendemos LED
        delay(1000);
        digitalWrite(leds[j], LOW); //Apagamos LED
    }
    return;
}


void secuencia_aditiva(int leds[4]) {
    int j;
    for(j = 0; j < 4; j++){
        digitalWrite(leds[j], HIGH); //Encendemos LED
        delay(1000);
    }
    for(j = 0; j < 4; j++) {
        digitalWrite(leds[j], LOW); //Encendemos LED
    }
    return;
}
