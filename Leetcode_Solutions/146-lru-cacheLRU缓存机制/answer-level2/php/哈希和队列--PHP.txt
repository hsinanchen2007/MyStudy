### 解题思路
用哈希存储元素，用队列来维护key的淘汰顺序，队尾的优先淘汰。这题看起来容易，写起来费劲容易出错，不好debug。另：PHP为啥没有类似Java的有序字典LinkedHashMap。现在发现PHP的有序数组太弱了。

发现PHP函数参数很随意，容易用混。
```
strpos ( string $haystack , mixed $needle [, int $offset = 0 ] ) : int

array_key_exists ( mixed $key , array $array ) : bool

array_search ( mixed $needle , array $haystack [, bool $strict = false ] ) : mixed

```

strpos第一个参数是字符串，如果给数组返回NULL
```
php -r '$string = [1, 2]; var_dump(strpos($string, 1));'

NULL
```


注意：优先级， !== 高于 =

### 代码

```php
class LRUCache {
    private $capacity = null;
    private $map  = [];
    private $list = [];

    /**
     * @param Integer $capacity
     */
    function __construct($capacity) {
        $this->capacity = $capacity;
    }

    /**
     * @param Integer $key
     * @return Integer
     */
    function get($key) {
        // 赋值语句需要括号，优先级低于 !==
        if (($pos = array_search($key, $this->list)) !== false) {
            unset($this->list[$pos]);
            array_unshift($this->list, $key);
            return $this->map[$key];
        }

        return -1;
    }

    /**
     * @param Integer $key
     * @param Integer $value
     * @return NULL
     */
    function put($key, $value) {
        if (($pos = array_search($key, $this->list)) !== false) {
            unset($this->list[$pos]);
            array_unshift($this->list, $key);
        } else {
            if ($this->capacity == count($this->list)) {
                $del_key = array_pop($this->list);
                unset($this->map[$del_key]);
            }

            array_unshift($this->list, $key);
        }

        $this->map[$key] = $value;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * $obj = LRUCache($capacity);
 * $ret_1 = $obj->get($key);
 * $obj->put($key, $value);
 */
```

### 性能
执行用时 :828 ms, 在所有 PHP 提交中击败了12.86%的用户
内存消耗 :36.4 MB, 在所有 PHP 提交中击败了88.24%的用户

### 算法复杂度
