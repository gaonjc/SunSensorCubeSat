int analogPin0 = A0;  // Define analog pin 0 (GPIO 26) physical pin 31
int analogPin1 = A1;  // Define analog pin 1 (GPIO 27) physical pin 32
int value0 = 0;       // Variable to store the value from A0
int value1 = 0;       // Variable to store the value from A1

void setup() {
  Serial.begin(115200);  //initialize serial baud = 115200
  pinMode(analogPin0, INPUT);  //set as inputs
  pinMode(analogPin1, INPUT);  
}

int readAnalogAverage(int pin, int samples) { //avg filter
  long sum = 0;
  for (int i = 0; i < samples; i++) {
    sum += analogRead(pin);
    delay(10);  
  }
  return sum / samples;
}

void loop() {
  // read voltages as avg
  value0 = readAnalogAverage(analogPin0, 10);  
  value1 = readAnalogAverage(analogPin1, 10);  
  
  // print to serial
  Serial.print("A0 Value: "); 
  Serial.print(value0);
  Serial.print(" | A1 Value: "); 
  Serial.println(value1);

  // compare (greater voltage = greater brightness)
  if (value0 > value1) {
    Serial.println("A0 is brighter than A1");
  } else if (value0 < value1) {
    Serial.println("A1 is brighter than A0.");
  } else {
    Serial.println("A0 and A1 have equal voltages.");
  }

  delay(1000);  
}