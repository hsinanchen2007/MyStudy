```php
class MyHashSet {
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->hash = [];
    }
  
    /**
     * @param Integer $key
     * @return NULL
     */
    function add($key) {
        $this->hash[$key] = '';
    }
  
    /**
     * @param Integer $key
     * @return NULL
     */
    function remove($key) {
        unset($this->hash[$key]);
    }
  
    /**
     * Returns true if this set contains the specified element
     * @param Integer $key
     * @return Boolean
     */
    function contains($key) {
        return isset($this->hash[$key]);
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * $obj = MyHashSet();
 * $obj->add($key);
 * $obj->remove($key);
 * $ret_3 = $obj->contains($key);
 */
```