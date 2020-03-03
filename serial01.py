import serial
import time
import pyautogui

ArduinoSerial = serial.Serial('COM4',9600)

time.sleep(2)

while 1:
    incoming = str (ArduinoSerial.readline()) ##read the serial data and print it as line

    if 'L' in incoming:
        pyautogui.press('left')	
        print('LEFT STEP')
		
    if 'R' in incoming:
        pyautogui.press('right')
        print('RIGHT STEP')

    if 'U' in incoming:
        pyautogui.press('up')
        print('JUMP')

    if 'D' in incoming:
        pyautogui.press('down')
        print('SQUAT')

    if 'H' in incoming:
        pyautogui.press('space')
        print('HOVERBOARD')
