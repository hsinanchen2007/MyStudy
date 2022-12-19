
用php开发的话，注意 array_unshift([], value) , array_search(key, []) .
思想倒是很简单，get ，put 都要把当前的key移动到最前面，map存储了hash映射关系。 put的时候如果超了，就把队尾的元素删除 array_pop . 如果不超，则删除原来的再插入新的。 删除原来的时候，需要array_search 先找到位置再删除。

```
class LRUCache {
    /**
     * @param Integer $capacity
     */
    function __construct($capacity) {
        $this->capacity = $capacity;
        $this->list = [];
        $this->map = [];
    }

    /**
     * @param Integer $key
     * @return Integer
     */
    function get($key) {
        if(in_array($key, $this->list)){
            $value = $this->map[$key];
            $pos = array_search($key, $this->list);
            unset($this->list[$pos]);
            array_unshift($this->list, $key);
            return $value;
        }else{
            return -1;
        }
    }

    /**
     * @param Integer $key
     * @param Integer $value
     * @return NULL
     */
    function put($key, $value) {
        if(in_array($key, $this->list)){
            $pos = array_search($key, $this->list);
            unset($this->list[$pos]);
        }else{
            if(count($this->list) >= $this->capacity){
                array_pop($this->list);
            }
        }
        array_unshift($this->list,$key);
        $this->map[$key] = $value;
    }
}
```
