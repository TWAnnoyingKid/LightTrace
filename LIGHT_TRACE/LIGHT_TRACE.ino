#include <Servo.h>

Servo myservo;

int pos = 0;  // Variable to store the servo position.
int inputPhotoLeft = A1; // Easier to read, instead of just 1 or 0.
int inputPhotoRight = A0;

int Left = 0; // Store readings from the photoresistors.
int Right = 0; // Store readings from the photoresistors.

void setup()
{
  Serial.begin(9600);
  myservo.attach(9); // Attach servo to pin 9.
}

void loop()
{
  // Reads the values from the photoresistors to the Left and Right variables.
  Left = analogRead(inputPhotoLeft);
  Right = analogRead(inputPhotoRight);

  if (Left > (Right +20))
  {
    if (pos < 179){
      pos++;
      myservo.write(pos);
      Serial.println (Left);
      Serial.println (Right);
    }
  }

  if (Right > (Left +20))
  {
    if (pos > 1){
      pos= pos-
      1;
      myservo.write(pos);
      Serial.println (Left);
      Serial.println (Right);
    }
  }

// Added some delay, increase or decrease if you want less or more speed.
  delay(10);
}
