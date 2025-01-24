int xPin = A1;
int yPin = A0;
int buttonPin = 2;

int xPosition = 0;
int yPosition = 0;
int button = 0;
int red = 0;
int green = 0;
int blue = 0;
int rez = 0;

void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  button = digitalRead(buttonPin);
  red = map(xPosition, 0, 1023, 0, 255);
  green = map(yPosition, 0, 1023, 0, 255);
  if (xPosition - yPosition > 500) {
    blue = map(xPosition - yPosition, 500, 1023, 255, 0);
    analogWrite(11, red);
    analogWrite(10, green);
    analogWrite(9, blue);
  }
  else if (yPosition - xPosition > 500) {
    blue = map(yPosition - xPosition, 500, 1023, 255, 0);
    analogWrite(11, red);
    analogWrite(10, green);
    analogWrite(9, blue);
  }
  else {
    blue = 255 - (red + green)/2;
    analogWrite(11, red);
    analogWrite(10, green);
    analogWrite(9, blue);
  }
}
