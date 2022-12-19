### 解题思路
![image.png](https://pic.leetcode-cn.com/4801aef1055cbf3ff1a4c960e37d5b8a98776e245dd95ef211784026dbcfc53a-image.png)

用数组垂死挣扎，勉强没超时。orz


### 代码

```php
class LFUCache {
    /**
     * @param Integer $capacity
     */
    public $cap;
    public $cache;
    public $time;
    function __construct($capacity) {
        $this->cap = $capacity;
        $this->cache = [];
        $this->time = 0;
    }

    /**
     * @param Integer $key
     * @return Integer
     */
    function get($key) {
        $this->time ++;
        if ($this->cap > 0 && isset($this->cache[$key])){
            $this->cache[$key]['count'] ++;
            $this->cache[$key]['time'] = $this->time;
            return $this->cache[$key]['val'];
        }
        return -1;
    }

    /**
     * @param Integer $key
     * @param Integer $value
     * @return NULL
     */
    function put($key, $value) {
        if($this->cap == 0){
            return;
        }
        $this->time ++;
        if (isset($this->cache[$key])){ // 如果存在就替换
            $this->cache[$key]['val'] = $value;
            $this->cache[$key]['count'] ++;
            $this->cache[$key]['time'] = $this->time;
        }else {
            if (count($this->cache) == $this->cap) { // 到达最大容量，需要删除元素了。
                array_multisort(array_column($this->cache, 'count'), SORT_ASC, array_column($this->cache, 'time'), SORT_ASC, $this->cache);
                // 按照出现次数和时间排正序，但是返回的新的数组会把原来的key值删除然后替换成索引值。
                array_shift($this->cache); // 删除出现频率最低且最近最少使用的键
                $this->cache = array_column($this->cache,NULL,'key'); // 重新生成按照$key作为数组的key值的新数组
            }
            $this->cache[$key] = [
                'key' => $key, 'val' => $value, 'count' => 1, 'time' => $this->time
            ];
        }
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * $obj = LFUCache($capacity);
 * $ret_1 = $obj->get($key);
 * $obj->put($key, $value);
 */
```