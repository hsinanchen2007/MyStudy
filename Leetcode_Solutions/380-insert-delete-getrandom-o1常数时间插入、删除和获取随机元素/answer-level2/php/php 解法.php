```
class RandomizedSet {
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->map = [];
        $this->list = [];
    }

    private $map;
    private $list;
  
    /**
     * Inserts a value to the set. Returns true if the set did not already contain the specified element.
     * @param Integer $val
     * @return Boolean
     */
    function insert($val) {
        if(array_key_exists($val,$this->map)) return false;
        $this->list[] = $val;
        $this->map[$val] = count($this->list)-1;
        return true;
    }
  
    /**
     * Removes a value from the set. Returns true if the set contained the specified element.
     * @param Integer $val
     * @return Boolean
     */
    function remove($val) {
        if(!array_key_exists($val,$this->map)) return false;
        $this->map[end($this->list)] = $this->map[$val];
        $this->swap($this->list,$this->map[$val],count($this->list)-1);
        array_pop($this->list);
        unset($this->map[$val]);
        return true;
    }

    function swap(&$arr, $i, $j){
        $tmp = $arr[$i];
        $arr[$i] = $arr[$j];
        $arr[$j] = $tmp;
    }
  
    /**
     * Get a random element from the set.
     * @return Integer
     */
    function getRandom() {
        return $this->list[rand(0,count($this->list)-1)];
    }
}
```
