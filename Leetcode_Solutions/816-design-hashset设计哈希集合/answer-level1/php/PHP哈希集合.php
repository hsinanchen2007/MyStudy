**PHP不适合设计数据结构**
![image.png](https://pic.leetcode-cn.com/2cd8d0a7e81c04f097af2018f7172725b7c9065888f40f1ae6ff26f5a3272185-image.png)
```
class MyHashSet {
    private $hash=[];
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        
    }
  
    /**
     * @param Integer $key
     * @return NULL
     */
    function add($key) {
        $this->hash[$key] = 1;
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
        return isset($this->hash[$key]) ? true : false;
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
