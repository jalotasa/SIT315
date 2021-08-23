
int interrCount = 0;
 
void setup() 
{
 
  pinMode( ledY,OUTPUT );
  Serial.begin(9600);
   

  digitalWrite( ledY,0 );
   
  attachInterrupt(0, interruptChange, RISING );
}
 
void loop() {
  interrCount++;
  if ( interrCount == 10 ) 
  {
    interrCount = 0;
    digitalWrite( ledY,0 );
  }
   
  delay(300);

}
 
void interruptChange() 
{
  digitalWrite( ledY,1 );
  Serial.print("High");
  
}
