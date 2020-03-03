// INSTRUCTIONS: This sketch connects the serial monitor to the python
// script. Upload this sketch on to the arduino first then run the python 
// script. Always close serial monitor/plotter before running python script
// as both cannot be run simultaneously.

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
int xRaw, yRaw, zRaw, xScaled, yScaled, zScaled, button;
int count = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {   
  // Read raw values.
  xRaw = analogRead(xInput);
  yRaw = analogRead(yInput);
  zRaw = analogRead(zInput);

  // BUTTON
  button = analogRead(pushButton);
  if (button == 0) {
    while (button == 0) {
      button = analogRead(pushButton);
    }
    if (button > 0) {
      button = analogRead(pushButton);
      Serial.println('H');
    }
    button = analogRead(pushButton);
  }
  
  // Convert raw values to scaled values.
  xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
  yScaled = map(yRaw, yRawMax, yRawMin, -3000, 3000);
  zScaled = map(zRaw, zRawMax, zRawMin, -3000, 3000);

  // PYTHON CONNECTION: Prints a letter to serial monitor to press down
  // appropriate key.
  if (zScaled < -7000) {     // Jump
    Serial.println('U');
    while (zScaled < -7000 && count < 12) {
      count ++;
      zRaw = analogRead(zInput);
      zScaled = map(zRaw, zRawMax, zRawMin, -3000, 3000);
    }
    count = 0;
    while (zScaled >= -7000 && count < 40) {
      count ++;
      zRaw = analogRead(zInput);
      zScaled = map(zRaw, zRawMax, zRawMin, -3000, 3000);
    }
    count = 0;
    while (zScaled < -7000 && count < 12) {
      count ++;
      zRaw = analogRead(zInput);
      zScaled = map(zRaw, zRawMax, zRawMin, -3000, 3000);
    }
    count = 0;
    delay(800); //750
  }

  if (zScaled > -20) {       // Squat
    Serial.println('D');
    while (zScaled > -20 && count < 12) {
      count ++;
      zRaw = analogRead(zInput);
      zScaled = map(zRaw, zRawMax, zRawMin, -3000, 3000);
    }
    count = 0;
    while (zScaled <= -20 && count < 12) {
      count ++;
      zRaw = analogRead(zInput);
      zScaled = map(zRaw, zRawMax, zRawMin, -3000, 3000);
    }
    count = 0;
    while (zScaled > -20 && count < 12) {
      count ++;
      zRaw = analogRead(zInput);
      zScaled = map(zRaw, zRawMax, zRawMin, -3000, 3000);
    }
    count = 0;
    delay(700);
  }
  
  if (xScaled > 1300) {       // Left
    Serial.println('L');
    count = 0;
    while (xScaled > 1300 && count < 30) {
      count ++;
      xRaw = analogRead(xInput);
      xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
    }
    count = 0;
    while (xScaled <= 1300 && xScaled >= -1300 && count < 30) {
      count ++;
      xRaw = analogRead(xInput);
      xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
    }
    count = 0;
    while (xScaled < -1300 && count < 30) {
      count ++;
      xRaw = analogRead(xInput);
      xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
    }
    count = 0;
    delay(400);
  }
  
  if (xScaled < -1300) {        // Right
    Serial.println('R');
    while (xScaled < -1300 && count < 30) {
      count ++;
      xRaw = analogRead(xInput);
      xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
    }
    count = 0;
    while (xScaled >= -1500 && xScaled <= 1500 && count < 30) {
      count ++;
      xRaw = analogRead(xInput);
      xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
    }
    count = 0;
    while (xScaled > 1500 && count < 30) {
      count ++;
      xRaw = analogRead(xInput);
      xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
    }
    count = 0;
    delay(400);
  }

}




