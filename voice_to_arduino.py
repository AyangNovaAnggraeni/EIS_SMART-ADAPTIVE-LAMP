import speech_recognition as sr
import serial
import time

# Sesuaikan dengan port Arduino kamu
arduino = serial.Serial('COM4', 9600)  
time.sleep(2)

r = sr.Recognizer()

print("Voice control active. Say 'on' or 'off'...")

while True:
    try:
        with sr.Microphone() as source:
            print("Listening...")
            audio = r.listen(source, phrase_time_limit=3)
            command = r.recognize_google(audio)
            print("You said:", command)

            if "on" in command.lower():
                arduino.write(b'ON\n')
                print("Lamp turned ON")

            elif "off" in command.lower():
                arduino.write(b'OFF\n')
                print("Lamp turned OFF")

    except sr.UnknownValueError:
        print("Sorry, didn't catch that.")
    except KeyboardInterrupt:
        print("\nProgram stopped by user.")
        break
