from datetime import datetime

import serial
from xbee import XBee
import sqlite3

conn = sqlite3.connect('maskReading.db')
serial_port = serial.Serial('COM8')
#xbee = XBee(serial_port)



while True:
    res = serial_port.read()
    resD = res.decode('utf8')
    print(resD)
    currentTime = datetime.now()
    timestamp = currentTime.strftime('%d - %m -%Y %H:%M:%S')
    print(timestamp)
# while True:
#     c = conn.cursor()
#
#     c.execute('''CREATE TABLE maskReadings
#                  (date text, ID int , reading float)''')
#
#     c.execute("INSERT INTO maskReadings VALUES (xbee.wait_read)")
#     try:
#
#         print (xbee.wait_read_frame())
#         print("testing")
#         conn.commit()
#     except KeyboardInterrupt:
#         break

serial_port.close()




