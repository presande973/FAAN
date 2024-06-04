
const int buttonPin = 3;
const int motorPin = 9;

bool buttonState = 0;
bool lastButtonState = buttonState;
int buttonCount = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonCount++;
    }
    delay(10);
  }
  lastButtonState = buttonState;
  if (buttonCount % 2 == 0) {
    digitalWrite(motorPin, HIGH);
    Serial.println("motor ON");
  }
  else {
    digitalWrite(motorPin, LOW);
    Serial.println("motor OFF");
  }
}
