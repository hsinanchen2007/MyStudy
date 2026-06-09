### 解题思路
满足条件
0、$n > 0
1、$n & ($n - 1) == 0
注意：&&优先级高于&

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Boolean
     */
    function isPowerOfTwo($n) {
        return $n > 0 && ($n & ($n - 1)) == 0;
    }
}
```