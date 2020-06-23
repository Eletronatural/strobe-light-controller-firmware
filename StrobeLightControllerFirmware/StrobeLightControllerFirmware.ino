/*
   Strobe Light Controller Firmware
   Validated for devices: ESP8266 ESP-01
   Created at 2020-06-23 by Gustavo Rubin (gusrubin@gmail.com)
*/

const int buttonPin = 2; // the number of the pushbutton pin
const int ledPin =  LED_BUILTIN;// the number of the LED pin
const int lightPin =  0; // the number of the light pin

int buttonState = 0; // variable for reading the pushbutton status
int ledState = HIGH; // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0; // will store last time LED was updated

// constants won't change:
const long interval = 50; // interval at which to blink (milliseconds)

void setup() {
  Serial.begin(115200);
  Serial.println("Booting...");

  Serial.println("Setup GPIOs");
  pinMode(ledPin, OUTPUT); // Initialize the BUILTIN_LED pin as an output
  // initialize the light pin as an output:
  pinMode(lightPin, OUTPUT);
  digitalWrite(lightPin, HIGH);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (buttonState == LOW) {
    // Blink LED
    if (currentMillis - previousMillis >= interval) {
      // save the last time you blinked the LED
      previousMillis = currentMillis;

      // if the LED is off turn it on and vice-versa:
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }

      // set the LED with the ledState of the variable:
      digitalWrite(ledPin, ledState);
      // set the light with the ledState of the variable:
      digitalWrite(lightPin, ledState);
    }
  } else {
    ledState = HIGH;
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
    // set the light with the ledState of the variable:
    digitalWrite(lightPin, ledState);
  }
}
