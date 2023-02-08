#include <Manchester.h>
#include <Servo.h>
#include <Ultrasonic.h>

#define RX_PIN 2
#define LED_PIN 13
#define pino_Servo 8
#define lampada 9

uint16_t receivedData = 0;

HC_SR04 ultrassonic(6, 7);
Servo servo1;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(lampada, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(1200);

  servo1.attach(pino_Servo);
  servo1.write(0);

  man.setupReceive(RX_PIN, MAN_1200);
  man.beginReceive();
}

void loop() {
  if (man.receiveComplete()) {
    receivedData = man.getMessage();
    man.beginReceive();

    digitalWrite(LED_PIN, HIGH);
    servo1.write(180);
    Serial.print("distancia: ");
    Serial.println(ultrassonic.distance());
    if (ultrassonic.distance() < 10 ) {
      servo1.write(0);
      servo1.write(90);
      digitalWrite(lampada, HIGH);
      delay(5000);
      digitalWrite(lampada, LOW);

      Serial.print("Received value: ");
      Serial.println(receivedData);
      digitalWrite(LED_PIN, LOW);
    }
   
  }
   
}
