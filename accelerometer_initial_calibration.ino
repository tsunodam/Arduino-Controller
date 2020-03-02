// INSTRUCTIONS: To begin using the arduino controller, first run the 
// accelerometer_initial_calibration.ino sketch. Calibrate each positive/negative 
// axes be entering the relevant menu values. Check calibrated min/max values
// and replace values in the INPUT VARIABLE DECLARATION section of the 
// accelerometer.ino and accelerometer_data_collection.ino sketch with 
// corresponding values from this sketch.

// VARIABLE DECLARATION
const int xInput = A0; // X-Axis Analog Pin Input (A0)
const int yInput = A2; // Y-Axis Analog Pin Input (A1)
const int zInput = A1; // Z-Axis Analog Pin Input (A2)
const int sampleSize = 20; // Collect 20 samples for calibration
int xRawMin, xRawMax, yRawMin, yRawMax, zRawMin, zRawMax;
int input;

void setup() {
  Serial.begin(9600);
  Serial.println("Running calibration sketch...");
  Serial.println("Enter (1) For Positive X-Axis Calibration");
  Serial.println("Enter (2) For Negative X-Axis Calibration");
  Serial.println("Enter (3) For Positive Y-Axis Calibration");
  Serial.println("Enter (4) For Negative Y-Axis Calibration");
  Serial.println("Enter (5) For Positive Z-Axis Calibration");
  Serial.println("Enter (6) For Negative Z-Axis Calibration");
  Serial.println("Enter (7) To Check Calibrated Values");
}

void loop() {
  input = Serial.read();
  if (input == '1') {
    Serial.print("Positive X-Axis Calibration Begin: ");
    xRawMax = xCalibration();
    Serial.println(xRawMax);
  }
  if (input == '2') {
    Serial.print("Negative X-Axis Calibration Begin: ");
    xRawMin = xCalibration();
    Serial.println(xRawMin);
  }
  if (input == '3') {
    Serial.print("Positive Y-Axis Calibration Begin: ");
    yRawMax = yCalibration();
    Serial.println(yRawMax);
  }
  if (input == '4') {
    Serial.print("Negative Y-Axis Calibration Begin: ");
    yRawMin = yCalibration();
    Serial.println(yRawMin);
  }
  if (input == '5') {
    Serial.print("Positive Z-Axis Calibration Begin: ");
    zRawMax = zCalibration();
    Serial.println(zRawMax);
  }
  if (input == '6') {
    Serial.print("Negative Z-Axis Calibration Begin: ");
    zRawMin = zCalibration();
    Serial.println(zRawMin);
  }
  if (input == '7') {
    Serial.println("Min/Max Values Check:");
    Serial.print("xRawMin: ");
    Serial.print(xRawMin);
    Serial.print(" xRawMax: ");
    Serial.println(xRawMax);
    Serial.print("yRawMin: ");
    Serial.print(yRawMin);
    Serial.print(" yRawMax: ");
    Serial.println(yRawMax);
    Serial.print("zRawMin: ");
    Serial.print(zRawMin);
    Serial.print(" zRawMax: ");
    Serial.println(zRawMax);
  }
}

// CALLIBRATION FUNCTIONS: Reads in relevant pin reading takes a #sampleSize samples to find average.
int xCalibration() {
  long reading = 0;
  for (int i = 0; i < sampleSize; i++)
  {
    reading += analogRead(xInput);
  }
  return reading/sampleSize;
}

int yCalibration() {
  long reading = 0;
  for (int i = 0; i < sampleSize; i++)
  {
    reading += analogRead(yInput);
  }
  return reading/sampleSize;
}

int zCalibration() {
  long reading = 0;
  for (int i = 0; i < sampleSize; i++)
  {
    reading += analogRead(zInput);
  }
  return reading/sampleSize;
}
