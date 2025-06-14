import speech_recognition as sr
import serial
import time

# Sesuaikan dengan port Arduino kamu
arduino = serial.Serial('COM4', 9600)  
time.sleep(2)

r = sr.Recognizer()
r.energy_threshold = 300  # atau coba turunkan ke 200, 150 dst sesuai tes
r.dynamic_energy_threshold = False

print("Voice control active. Say 'on' or 'off'...")

while True:
    try:
        with sr.Microphone() as source:
            print("Listening...")
            audio = r.listen(source, phrase_time_limit=3)
            command = r.recognize_google(audio, language='id-ID')
            print("You said:", command)

            if any(word in command.lower() for word in ["on", "nyala", "hidup"]):
                arduino.write(b'ON\n')
                print("Lampu nyala")

            elif any(word in command.lower() for word in ["off", "mati"]):
                arduino.write(b'OFF\n')
                print("Lamp mati")

    except sr.UnknownValueError:
        print("Sorry, didn't catch that.")
    except KeyboardInterrupt:
        print("\nProgram stopped by user.")
        break
