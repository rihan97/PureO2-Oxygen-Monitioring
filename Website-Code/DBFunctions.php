<?php
 
/**
 * This class will have all methods to deal with database manipulation, CRUD
 *  
 */
 
class DBFunctions
{
 
    private $conn;
 
    function __construct() 
    {
        require_once 'DBConnect.php';
        // opening db connection
        $db = new DBConnect(); //we create object from the class
        $this->conn = $db->connect(); 
    }
 
    
    /**
     *  Function to create new sensor entry in database table
     *  @param String $sensorname
     *  @param String $sensortype
     *  @param String $sensorlocation
     *                       
     */                                        
    public function createSensor($sensorname, $sensortype, $sensorlocation)
    {     
      $stmt = $this->conn->prepare("INSERT INTO sensors (name,type,location) VALUES(?,?,?)");
      $stmt->bind_param("sss", $sensorname,$sensortype,$sensorlocation);
      $result = $stmt->execute();
      $stmt->close();
      if($result)//successfully inserted
      { 
        return $this->conn->insert_id;
      }
      else //meaning execution was not possible
      {
        return NULL;
      }
    }
    
    /**
     * Fetching all sensors
     * @param none
     */
    public function getAllSensors() 
    {
        $stmt = $this->conn->prepare("SELECT * FROM sensors");        
        $stmt->execute();
        $sensors = $stmt->get_result();
        $stmt->close();
        return $sensors;
    }
    
    /**
     * Fetching single sensor entry from db
     * @param String $id -> id of sensor
    */
    public function getSensor($id) 
    {
        $stmt = $this->conn->prepare("SELECT * FROM sensors WHERE id=?");
        $stmt->bind_param("i", $id);        
        if ($stmt->execute()) 
        {
            $sensor = $stmt->get_result()->fetch_assoc();
            $stmt->close();
            return $sensor;
        } 
        else 
        {
            return NULL;
        }
    }    
 
    /**
     * Updating sensor
     * @param String $id -> id of sensor
     *  @param String $sensorname
     *  @param String $sensortype
     *  @param String $sensorlocation
     */
    public function updateSensor($id, $sensorname, $sensortype, $sensorlocation) 
    {
        $stmt = $this->conn->prepare("UPDATE sensors SET name=?,type=?,location=? WHERE id=?");
        $stmt->bind_param("sssi", $sensorname, $sensortype, $sensorlocation, $id);
        $stmt->execute();
        $num_affected_rows = $stmt->affected_rows;
        $stmt->close();
        return $num_affected_rows > 0;//will return true if affected row is greater than 0, else false
    }
 
    /**
     * Deleting a sensor
     * @param String $id -> id of sensor to delete
     */
    public function deleteSensor($id) 
    {
        $stmt = $this->conn->prepare("DELETE FROM sensors WHERE id = ?");
        $stmt->bind_param("i", $id);
        $stmt->execute();
        $num_affected_rows = $stmt->affected_rows;
        $stmt->close();
        return $num_affected_rows > 0;
    }
    
    //    
    
}//end of class
 
?>
