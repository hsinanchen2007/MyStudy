### 解题思路
1. 当成字符串反转
2. intval转数字
3. 判断大小，负数则反一下
4. 判断范围

### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        $r = intval(strrev($x));
        if($x < 0) $r = 0 - $r;
        return $r > 2147483647 || $r < -2147483648 ? 0 : $r;
    }
}
```