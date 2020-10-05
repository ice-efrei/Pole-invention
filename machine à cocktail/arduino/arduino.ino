#include <Stepper.h> 

// Définir le nombre de pas par tour 
int NbrPas = 200; 
Stepper MonMoteur(NbrPas, 8, 9, 10, 11); 
int interrupteur_pin_number = 5; 
int buttonState = 0;  

void setup() { 
  // Vitesse à 60 tours/min 
  MonMoteur.setSpeed(200); 
  Serial.begin(9600); 
  pinMode(interrupteur_pin_number, INPUT_PULLUP); 
} 


void loop() { 
  buttonState = 0;
  while(buttonState == 0){
    if (digitalRead(interrupteur_pin_number)== HIGH){
      buttonState ++;
    }
    if(buttonState % 2 == 0){
      MonMoteur.step(-1);
    }
    else if(buttonState % 2 == 1){
      MonMoteur.step(1);
    }
  }
