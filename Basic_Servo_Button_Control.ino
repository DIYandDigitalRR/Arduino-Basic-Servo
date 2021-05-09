const int button = A0;
int start1=0;
int stop1=180;

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup () {
Serial.begin(9600);
myservo.attach(6);

}
  enum SWITCHSTATES
  {
    ST_OFF1,
    ST_OFF2,
    ST_STRAIGHT,
    ST_TURN,
  };
  SWITCHSTATES switchState = ST_OFF1;

  void loop() {
    int buttonRead = analogRead(button);
    delay(200);
    switch (switchState)
    {
      case ST_OFF1:
        switchoff1(buttonRead); //sets up changes to ST_OFF1
        break;
      case ST_OFF2:
        switchoff2(buttonRead); //sets up changes to ST_OFF2
        break;
      case ST_STRAIGHT:
        switchstraight(buttonRead); //sets up changes to ST_STRAIGHT
        break;
      case ST_TURN:
        switchturn(buttonRead); // sets up changes to ST_TURN
        break;
    }
  }

  void switchoff1(int buttonRead) {
    myservo.write(start1);

    if (buttonRead > 500) {
      switchState = ST_TURN; //switches to different state

    }
  }

  void switchturn(int buttonRead) {
    for (pos = start1; pos <= stop1; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    switchState = ST_OFF2; //chages to ST_OFF2
  }

  void switchoff2(int buttonRead) {
    myservo.write(stop1);

    if (buttonRead > 500) {
      switchState = ST_STRAIGHT; //switches to Straight

    }
  }

  void switchstraight(int buttonRead) {
    for (pos = stop1; pos >= start1; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
      switchState = ST_OFF1; //chages to ST_OFF1
    }



  }
