int ledPin = 5;
int Buzzer = 6;
int inputPin = 2;
int pirState = LOW;
int val = 0;

void setup() {
 pinMode(ledPin, OUTPUT);
 pinMode(Buzzer, OUTPUT);
 pinMode(inputPin, INPUT);

 Serial.begin(9600);

}

void loop() 
{
  val = digitalRead(inputPin);
  int value_ldr = analogRead(A0);

  if ((300>value_ldr) && (val==HIGH))
  {
    if (val == HIGH) 
    {
      digitalWrite(ledPin, HIGH);
      digitalWrite(Buzzer, 1);
      delay(5000);
      if (pirState == LOW) 
      {
        Serial.println("Motion detected");
        pirState = HIGH;
      }
    }
    else
    {
      digitalWrite(ledPin, LOW);
      digitalWrite(Buzzer, 0);
      delay(5000);
      if (pirState == HIGH)
      
      {
        Serial.println("Motion ended");
        pirState = LOW;
      }
    }
  }
}
  
