const int pingPin = 9; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 10; // Echo Pin of Ultrasonic Sensor

void setup() {
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   long duration, inches, cm;
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(5);
   digitalWrite(pingPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(duration);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
   if(cm<=3000){
    //then write the condition to change the direction of the drone if there is an issue
   }
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
