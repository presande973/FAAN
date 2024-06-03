#define potPin A1 //potentiometer to control speed
#define motorPin A2 //motor

const int buttonPin = 8;  //toggle switch
bool buttonState = 0;
bool lastButtonState = buttonState;
int buttonPushCount = 0;
int potVal = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  potVal = analogRead(potPin) / 4;
  buttonState = digitalRead(buttonPin);
  if (lastButtonState != buttonState) {
    if (buttonState == 1) {
      buttonPushCount++;
      analogWrite(motorPin, potVal);
      Serial.println("ON");
    }
    else if (buttonState == 0) {
      analogWrite(motorPin, 0);
      Serial.println("OFF");
    }
  }
  lastButtonState = buttonState;
  //Serial.print("potVal = ");
  //Serial.println(potVal);
}
