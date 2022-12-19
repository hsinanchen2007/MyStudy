### 解题思路
初看跟706题没区别，如果按照706的写法，remove和contains都需要遍历。

优一点的解法还是添加的key作为数组的key, val为空。

### 代码

```php
class MyHashSet {
    private $list = [];
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
        $this->list[] = $key;
    }
  
    /**
     * @param Integer $key
     * @return NULL
     */
    function remove($key) {
        $res = [];
        foreach ($this->list as $val) {
            if ($val != $key) $res[] = $val;
        }

        $this->list = $res;
    }
  
    /**
     * Returns true if this set contains the specified element
     * @param Integer $key
     * @return Boolean
     */
    function contains($key) {
        foreach ($this->list as $val) {
            if ($val == $key) return true;;
        }

        return false;
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