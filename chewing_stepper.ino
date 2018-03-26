/*
 * This sketch controls the stepper motor which moves the
 * lower jaw of the mouth model as seen in the video posted
 * in the README. The motor is driven by a Big Easy driver 
 * board from SparkFun, Arduino R3, and a 15v power adapter.
 * This sketch was modeled off of Brian Schmalz' Easy Driver 
 * example from his website.
 */

int Distance = 0;  // Record the number of steps we've taken
// control speed of chewing, in between steps
int jawSpeedUp = 300;
int jawSpeedDown = 100;
// control speed of pause at top and bottom of chew
int pauseTime = 75;

void setup() {                
  pinMode(8, OUTPUT);     
  pinMode(9, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void loop() {
  // alternate step pin high/low at default 16th stepping
  digitalWrite(9, HIGH);
  delayMicroseconds(jawSpeedUp);          
  digitalWrite(9, LOW); 
  delayMicroseconds(jawSpeedDown);
  Distance = Distance + 1;   // record this step
  
  // Check to see if we are at the end of move up/down
  if (Distance == 750)
  {
    // Reverse direction; invert DIR signal, move down
    if (digitalRead(8) == LOW)
    {
      digitalWrite(8, HIGH);
    }
    // chew upwards
    else
    {
      digitalWrite(8, LOW);
    }
    // Reset our distance back to zero 
    Distance = 0;
    // Pause at top and bottom of chew
    delay(pauseTime);
  }
}

