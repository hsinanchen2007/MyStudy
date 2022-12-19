```
class PhoneDirectory {
    /**
     * Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory.
     * @param Integer $maxNumbers
     */
    function __construct($maxNumbers) {
        $this->map = [];
        $this->queue = [];
        for($i=0;$i<$maxNumbers;$i++){
            $this->map[$i] = 1;
            $this->queue[] = $i;
        }
    }
  
    /**
     * Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available.
     * @return Integer
     */
    function get() {
        if(empty($this->queue)) return -1;
        $get = array_shift($this->queue);
        $this->map[$get] = 0;
        return $get;
    }
  
    /**
     * Check if a number is available or not.
     * @param Integer $number
     * @return Boolean
     */
    function check($number) {
        return $this->map[$number]==1?true:false;
    }
  
    /**
     * Recycle or release a number.
     * @param Integer $number
     * @return NULL
     */
    function release($number) {
        if($this->map[$number] == 0){
            $this->map[$number] = 1;
            $this->queue[] = $number;
        }
    }
}
```
