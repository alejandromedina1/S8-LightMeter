const int PHOTOCELL_PIN = A0;
int sensorValue = 0;
int ledValue = 0;
int brightness = 0;

void setup()
{
  pinMode(PHOTOCELL_PIN, INPUT);
  Serial.begin(9600);
  
  for(int i = 1; i<=5; i++){
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  sensorValue = analogRead(PHOTOCELL_PIN);
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);
  
  for(int i = 1; i<=5; i++){
    ledValue = sensorValue/i;
    brightness = map(ledValue, 1023, 0, 0, 255);
    analogWrite(i, brightness);
    Serial.print("LED ");
    Serial.println(i);
    Serial.print(" brightness: ");
    Serial.println(brightness);
    delay(1000);
  }
  delay(5000);
}
