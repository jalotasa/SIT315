// C++ code
//
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(9, OUTPUT);
}

void loop()
{
  int distance;
  distance = 0.01723 * readUltrasonicDistance(3, 3);
  
  if (0.01723 * readUltrasonicDistance(3, 3) < 30) {
    String sth = String("  Distance ") + distance + "  Voltage High ";
    digitalWrite(9, HIGH);
    Serial.print(sth);
    
    
  } else {
    String sth = String("  Distance ") + distance + "  Voltage Low ";
    digitalWrite(9, LOW);
    
  }
  ;
  
  delay(10); // Delay a little bit to improve simulation performance
  
}