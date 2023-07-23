#include <Preferences.h>

#define led 2
#define btn 23

Preferences pref;
int status = false;

void setup() {
  Serial.begin(115200);
  pinMode(btn, INPUT);
  pinMode(led, OUTPUT);
  pref.begin("gpioState", false); // Initialize the Preferences library
  status = pref.getBool("ledStatus", false); // Read the LED status from preferences
  digitalWrite(led, status);
}

void loop() {
  if (digitalRead(btn) == true) {
    status = !status;
    digitalWrite(led, status);
    pref.putBool("ledStatus", status); // Save the LED status to preferences
    while (digitalRead(btn) == true);
  }
  delay(200);
}
