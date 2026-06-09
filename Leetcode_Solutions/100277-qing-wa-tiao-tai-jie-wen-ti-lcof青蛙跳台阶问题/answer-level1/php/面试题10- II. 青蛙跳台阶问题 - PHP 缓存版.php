### 解题思路
普通斐波那契，加静态缓存（空间换时间）

### 代码

```php
class Solution {

    public static $cache = [ 
        0 => 1,
        1 => 1,
        2 => 2
     ];

    /**
     * @param Integer $n
     * @return Integer
     */
    function numWays($n) {
        if(!isset(static::$cache[$n])) {
            static::$cache[$n] = ($this->numWays($n-1) + $this->numWays($n-2)) % 1000000007;
        }

        return static::$cache[$n];
    }
}
```