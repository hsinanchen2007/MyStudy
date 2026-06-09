### 解题思路
此处撰写解题思路

### 代码

```php
class MaxQueue {

    public $data;
    /**
     */
    function __construct() {
        $this->data = [];
    }

    /**
     * @return Integer
     */
    function max_value() {
        if($this->data){
            return max($this->data);
        } else {
            return -1;
        }
    }

    /**
     * @param Integer $value
     * @return NULL
     */
    function push_back($value) {
        $this->data[] = $value;
    }

    /**
     * @return Integer
     */
    function pop_front() {
        if($this->data){
            return  array_shift($this->data);
        } else {
            return -1;
        }
        
    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * $obj = MaxQueue();
 * $ret_1 = $obj->max_value();
 * $obj->push_back($value);
 * $ret_3 = $obj->pop_front();
 */
```