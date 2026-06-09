### 解题思路
判断当前值不为0且 ($n & ($n-1)) 处理后没有1 即只有一个1 。

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Boolean
     */
    function isPowerOfTwo($n) {
        return $n && !($n & ($n-1));
    }
}
```