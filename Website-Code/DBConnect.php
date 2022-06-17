<?php
 
/**
 * Database Connection class
 *  
 */
class DBConnect {
 
    private $conn;
 
    function __construct() {        
    }
 
    /**
     * Establishing database connection
     * @return database connection handler
     */
    function connect() {
        include_once 'config.php'; //we are including the config file to get hold of constants we defined
 
        // Connecting to mysql database
        $this->conn = new mysqli(DB_HOST, DB_USERNAME, DB_PASSWORD, DB_NAME);
 
        // Check for database connection error
        if (mysqli_connect_errno()) {
            echo "Failed to connect to MySQL: " . mysqli_connect_error();
        }
 
        // returning connection resource, to where ever this was requested from
        return $this->conn;
    }
 
}
 
?>
