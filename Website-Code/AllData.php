<!DOCTYPE html>
<html>
<head>
<style>
table{
  border-collapse: collapse;
  width: 50%;
}
th, td{
  text-align: left;
  padding: 8px
}
tr:nth-child(even{background-color: #f2f2f2}html
html
th{
background-color: #4CAF50 
}
</style>
</head>
<body>
  <table id= "latest" border="3" background-color:#4CAF50;>
  <thead>
  <h1>
  Logged Alarm Readings
  </h1>
<p>
</P>
<p>
 (Mask and Connector Valve) 
</P>
<tr>
  <th> ID </th>
  <th> Date & Time </th>
</tr>
<?php
$conn = mysqli_connect("localhost", "root", "password", "homeautomation");
  // Check connection
  if ($conn->connect_error) {
   die("Connection failed: " . $conn->connect_error);
  } 
  $sql = "SELECT id, dateTimeRecorded FROM sensorlog";
  $result = $conn->query($sql);
  if ($result->num_rows > 0) {
   // output data of each row
   while($row = $result->fetch_assoc()) {
    echo "</td><tr>" . $row["id"]. "<td><td>" . $row["dateTimeRecorded"]. "</td></tr>";
}
echo "</table>";
} else { echo "0 results"; }
$conn->close();
?>
</table>
</body>
</html>