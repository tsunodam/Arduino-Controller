// INSTRUCTIONS: This sketch helps analyze jump/squat/left-step/right-step 
// threshholds to optimize arduino performace. 
// To begin data collection, open serial plotter and enter 'x', 'y', 'z', or 'b'
// for x-axis, y-axis, z-axis, and button data collection respectively. Enter 's' 
// to stop data collection.

// INPUT VARIABLE DECLARATION: Use values from 
// accelerometer_initial_calibration.ino sketch and replace these values.
int xRawMin = 399;
int xRawMax = 265;
int yRawMin = 276;
int yRawMax = 407;
int zRawMin = 262;
int zRawMax = 396;

// VARIABLE DECLARATION
const int pushButton = A3; // Button is connected to analog pin #A5
const int xInput = A0; // X-Axis Analog Pin Input (A0)
const int yInput = A2; // Y-Axis Analog Pin Input (A1)
const int zInput = A1; // Z-Axis Analog Pin Input (A2)
const int sampleSize = 20;
int xRaw, yRaw, zRaw, xScaled, yScaled, zScaled, button, input;

void setup() {
  Serial.begin(9600);
  Serial.println("Running data collection sketch...");
  Serial.println("Enter (x) For X-Axis Data Collection");
  Serial.println("Enter (y) For Y-Axis Data Collection");
  Serial.println("Enter (z) For Z-Axis Data Collection");
  Serial.println("Enter (b) For Button Data Collection");
  Serial.println("Enter (s) To Stop Data Collection");
}

void loop() {
  input = Serial.read();
  
  // X-axis data collection.
  if (input == 'x') {
    while (input != 's') {
      xRaw = analogRead(xInput);
      xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
      Serial.println(xScaled);
      input = Serial.read();
    }
  }
  
  // Y-axis data collection.
  if (input == 'y') {
    while (input != 's') {
      yRaw = analogRead(yInput);
      yScaled = map(yRaw, yRawMax, yRawMin, -3000, 3000);
      Serial.println(yScaled);
      input = Serial.read();
    }
  }
  
  // Z-axis data collection.
  if (input == 'z') {
    while (input != 's') {
      zRaw = analogRead(zInput);
      long zScaled = map(zRaw, zRawMax, zRawMin, -3000, 3000);
      Serial.println(zScaled);
      input = Serial.read();
    }  
  }

  // Button data collection.
  if (input == 'b') {
    while (input != 's') {
      button = analogRead(pushButton);
      Serial.println(button);
      input = Serial.read();
    }
  }
  
}
