### 解题思路

2 的幂转化为二进制，首位为 1，其他都为 0. n & (n - 1) = 0

注意运算符的优先级，用括号处理

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Boolean
     */
    function isPowerOfTwo($n) {
        return $n > 0 && (($n & ($n - 1)) == 0);
    }
}
```