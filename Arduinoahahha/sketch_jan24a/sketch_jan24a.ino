int xPin = A1;
int yPin = A0;
int buttonPin = 2;

int xPosition = 0;
int yPosition = 0;
int button = 0;

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  button = digitalRead(buttonPin);
  Serial.print("|X: ");
  Serial.print(xPosition);
  Serial.print("|Y: ");
  Serial.print(yPosition);
  Serial.print("|Button: ");
  Serial.println(button);
  delay(50);
}
