```
class TwoSum {
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->map = [];
    }
  
    /**
     * Add the number to an internal data structure..
     * @param Integer $number
     * @return NULL
     */
    function add($number) {
        $this->map[$number] = isset($this->map[$number]) ? 2 : 1;
    }
  
    /**
     * Find if there exists any pair of numbers which sum is equal to the value.
     * @param Integer $value
     * @return Boolean
     */
    function find($value) {
        foreach($this->map as $num => $count){
            $target = $value - $num;
            if($target == $num && $count == 1) continue;
            if(isset($this->map[$target])) return true;
        }
        return false;
    }
}
```
