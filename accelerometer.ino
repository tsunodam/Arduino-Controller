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
int xRaw, yRaw, zRaw, xScaled, yScaled, zScaled, input, button;

void setup() {
  Serial.begin(9600);
}

void loop() {  
  // Read input.
  input = Serial.read();
  
  // Read raw values.
  xRaw = analogRead(xInput);
  yRaw = analogRead(yInput);
  zRaw = analogRead(zInput);
  button = analogRead(pushButton);

  // Convert raw values to scaled values.
  xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
  yScaled = map(yRaw, yRawMax, yRawMin, -3000, 3000);
  zScaled = map(zRaw, zRawMax, zRawMin, -3000, 3000);

  // PYTHON CONNECTION: Prints a letter to serial monitor to press down
  // appropriate key.
  if (zScaled > -200) {       // Squat
    Serial.println('D');
    while (zScaled > -200) {
      zRaw = analogRead(zInput);
      zScaled = map(zRaw, zRawMax, zRawMin, -3000, 3000);
    }
    while (zScaled <= -200) {
      zRaw = analogRead(zInput);
      zScaled = map(zRaw, zRawMax, zRawMin, -3000, 3000);
    }
    while (zScaled > -200) {
      zRaw = analogRead(zInput);
      zScaled = map(zRaw, zRawMax, zRawMin, -3000, 3000);
    }
    delay(200);
  }
  if (zScaled < -10000) {     // Jump
    Serial.println('U');
    while (zScaled < -10000) {
      zRaw = analogRead(zInput);
      zScaled = map(zRaw, zRawMax, zRawMin, -3000, 3000);
    }
    while (zScaled >= -10000) {
      zRaw = analogRead(zInput);
      zScaled = map(zRaw, zRawMax, zRawMin, -3000, 3000);
    }
    while (zScaled < -10000) {
      zRaw = analogRead(zInput);
      zScaled = map(zRaw, zRawMax, zRawMin, -3000, 3000);
    }
    delay(200);
  }
  if (xScaled < -1300) {      // Right-Step
    while (xScaled < 1300) {
      xRaw = analogRead(xInput);
      xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
    }
    if (xScaled > 1300) {
      Serial.println('R');
      xRaw = analogRead(xInput);
      xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
    }
    while(xScaled > 1000) {
      xRaw = analogRead(xInput);
      xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
    }
    xRaw = analogRead(xInput);
    xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
  }
  if (xScaled > 1300) {       // Left-Step
    while (xScaled > -1300) {
      xRaw = analogRead(xInput);
      xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
    }
    if (xScaled < -1300) {
      Serial.println('L');
      xRaw = analogRead(xInput);
      xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
    }
    while (xScaled < -1000) {
      xRaw = analogRead(xInput);
      xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
    }
    xRaw = analogRead(xInput);
    xScaled = map(xRaw, xRawMax, xRawMin, -3000, 3000);
  }

  // BUTTON
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
}
