/*
  Based on the "Fade" example
  designed for the ESP32-WROOM-DA

*/

int m_left = 23;
int m_right = 32; 
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(m_left, OUTPUT);
  pinMode(m_right, OUTPUT);
  Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(m_left, brightness);
  analogWrite(m_right, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(100);
}
