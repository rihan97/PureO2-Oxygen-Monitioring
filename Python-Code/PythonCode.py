import mysql.connector
from mysql.connector import Error
from mysql.connector import errorcode
import serial
from datetime import datetime

ser = serial.Serial('/dev/ttyUSB0',9600)

try:
   connection = mysql.connector.connect(host='localhost',
                             database='HomeAutomation',
                             user='rayhan',
                             password='password')

   sql_insert_query = """ INSERT INTO `sensorlog`
                          (`sensor_id`, `value`, `dateTimeRecorded`) VALUES ('%s','%s','%s')"""
   sql_insert_query = """ INSERT INTO `sensorlog`
                          (`sensor_id`, `value`, `dateTimeRecorded`) VALUES ('%s','%s','%s')"""
   sql_insert_query = """ INSERT INTO `sensorlog`
                          (`sensor_id`, `value`, `dateTimeRecorded`) VALUES ('%s','%s','%s')"""
   cursor = connection.cursor()
   result  = cursor.execute(sql_insert_query)
   connection.commit()
   print ("Record inserted successfully into sensorlog table")
except mysql.connector.Error as error :
    connection.rollback() #rollback if any exception occured
    print("Failed inserting record into sensorlog table {}".format(error))
finally:
    #closing database connection.
    if(connection.is_connected()):
        cursor.close()
        connection.close()
        print("MySQL connection is closed")




while True:
    incoming = ser.readline().strip().decode("utf-8")
    #lets split this csv into individual components and post it into the database using REST

    incoming = incoming.strip()

    #print(incoming)

    if incoming=="":
        #donothing
        #
        print ("empty incoming")
    else:
        parts = incoming.split(",")#splitting the csv with token ,
        lightValue = parts[0]
        #tempValue = parts[1]
        motionValue = parts[2]
        now = datetime.now()  # using python inbuilt function to extract current datetime
        timestamp = now.strftime('%Y-%m-%d %H:%M:%S') #format date time

        #form_data = {  # forming/organising the data before upload
                #'sensor_id': '%s',
                #'value': '%s',
                #'timestamp': dateTimeRecorded,



