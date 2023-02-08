#include <Manchester.h>

#define TX_PIN 2  //pin where your transmitter is connected
#define LED_PIN 13 //pin for blinking LED
#define button 7

bool buttonState;
uint8_t mensagem = 15;

void setup() {
 
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  pinMode(button, INPUT_PULLUP);
  man.setupTransmit(TX_PIN, MAN_1200);
  Serial.begin(1200);
} 
void loop() {
  buttonState = digitalRead(button);
  Serial.println(buttonState);
  
  if(buttonState == 0){
    digitalWrite(LED_PIN, HIGH);
    man.transmit(mensagem);
  
    digitalWrite(LED_PIN, LOW);  
  }
  
}
