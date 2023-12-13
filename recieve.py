import serial
import time

# port_name = "/dev/ttyUSB0"
port_name = "/dev/ttyXR0"
baud_rate = 115200
# baud_rate = 2000000

# Corrected the variable name
serial_port = serial.Serial(port_name, baud_rate)

if serial_port:
    try:
        while True:
            data = serial_port.write(b"Message\n")
            print(f"Sent: {data}")
            # received_data = serial_port.readline()
            # print(f"Received: {received_data}")
            time.sleep(1)
    except KeyboardInterrupt:
        # Allow the program to be terminated by KeyboardInterrupt (e.g., Ctrl+C)
        pass
    finally:
        # Close the serial port in a finally block to ensure it's closed even if an exception occurs
        serial_port.close()
