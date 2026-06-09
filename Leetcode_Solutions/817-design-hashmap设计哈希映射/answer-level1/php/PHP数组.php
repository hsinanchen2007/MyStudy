说实在的 PHP不适合底层数据结构实现
```
class MyHashMap {
    private $hash = [];
    /**
     * Initialize your data structure here.
     */
    function __construct() {

    }

    /**
     * value will always be non-negative.
     * @param Integer $key
     * @param Integer $value
     * @return NULL
     */
    function put($key, $value) {
        if (isset($this->hash[$key])) {
            $this->hash[$key] = $value;
        } else {
            $this->hash = $this->hash + [$key=>$value];
        }
    }

    /**
     * Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
     * @param Integer $key
     * @return Integer
     */
    function get($key) {
        return isset($this->hash[$key]) ? $this->hash[$key] : -1;
    }

    /**
     * Removes the mapping of the specified value key if this map contains a mapping for the key
     * @param Integer $key
     * @return NULL
     */
    function remove($key) {
        unset($this->hash[$key]);
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * $obj = MyHashMap();
 * $obj->put($key, $value);
 * $ret_2 = $obj->get($key);
 * $obj->remove($key);
 */
```
