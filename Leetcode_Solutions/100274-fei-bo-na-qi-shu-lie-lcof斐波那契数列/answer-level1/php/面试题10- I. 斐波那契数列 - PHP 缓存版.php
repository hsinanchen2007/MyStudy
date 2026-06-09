### 解题思路
普通斐波那契，加简单缓存防止超时（空间换时间）

### 代码

```php
class Solution {

    public static $cache = [0 => 0, 1 => 1];

    /**
     * @param Integer $n
     * @return Integer
     */
    function fib($n) {

        if(!isset(static::$cache[$n])) {
            static::$cache[$n] = $this->fib($n - 1) + $this->fib($n - 2);
        }

        return static::$cache[$n] % 1000000007;

    }
}
```