// just some pseudo-ish code before we've got the circuit set up
// our idea right now is for the dc motor to keep rotating, trying to lift a weight, causing the sphere to correct and roll forward
// by spinning the dc motor the other way, we can make the car reverse
// we can use a servo motor to move the dc motor to the right/left along the axis in the middle of the sphere that it's sitting on
// this should allow the car to turn by shifting it's center of mass

#include <Servo.h>

Servo myservo;

// need to decide what pins we're using
const int dcPin = ;
const int servoPin = ;

// need to decide this, using default vals from class for now
const int freq = 5000;
const int res = 8;

// right now I'm going based on the idea that we have one (us) sensor in front, and one on each side
// need to decide the pins
const int frontPin = ;
const int rightPin = ;
const int leftPin = ;

void setup() {
  myservo.attach(servoPin);
  myservo.write(45);
  ledcAttach(dcPin, freq, res);
  pinMode(frontPin, INPUT);
  pinMode(rightPin, INPUT);
  pinMode(leftPin, INPUT);
  Serial.begin(115200);
}


void loop() {
  right = analogRead(rightPin);
  if (right > // fill in here) {
    // turn right - move servo to the right pos, maybe keep it there until the right sensor reading is close enough - or time and figure out how long it takes
    myservo.write(90);
  } else {
    front = analogRead(frontPin);
    if (front < // fill in here) {
      // turn left - move servo to the left pos, maybe keep it there until the front sensor reading is far enough - or time and figure out how long it takes
      myservo.write(0);
    } else {
      // move forward
      myservo.write(45);
    }
  }
  ledcWrite(dcPin, 255);
  delay(1000); // change delay based on car's speed
  ledcWrite(dcPin, 0);
}