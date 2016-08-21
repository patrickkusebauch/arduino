void setup() {                
  pinMode(2, INPUT); 
  pinMode(3, INPUT); 
  pinMode(4, INPUT); 
  pinMode(5, INPUT); 
  pinMode(6, INPUT); 
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  int sensor1 = digitalRead(2);
  int sensor2 = digitalRead(3);
  int sensor3 = digitalRead(4);
  int sensor4 = digitalRead(5);
  int sensor5 = digitalRead(6);
  int total = 0;
  if(sensor1) {
    total += 15;
  }
  if(sensor2) {
    total += 10;
  }
  if(sensor3) {
    total += 10;
  }
  if(sensor4) {
    total += 10;
  }
  if(sensor5) {
    total += 10;
  }
  String text = String();
  float power = total / 55.0; //0-1
  int output = 255 - floor(power * 255);
  text = text + "Sensor1:" + sensor1 + " ;Sensor2:" + sensor2 + " ;Sensor3:" + sensor3 + " ;Sensor4:" + sensor4 + " ;Sensor5:" + sensor5 + " ;TOTAL: " 
  + total + " ;OUTPUT:" + output;
  Serial.println(text);
  analogWrite(11, output);
}
