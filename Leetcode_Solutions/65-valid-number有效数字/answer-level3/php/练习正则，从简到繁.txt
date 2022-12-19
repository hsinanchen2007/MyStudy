### 解题思路
从简到繁，如代码中的注释，此题坑很多“.1”和“1.”竟然也算true.

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isNumber($s) {
        // return preg_match('/^\d+$/',$s); //整数
        // return preg_match('/^\d*[\.]?\d+|\d+[\.]?\d*$/',$s); //整数和小数
        // return preg_match('/^[\-\+]?(\d*[\.]?\d+|\d+[\.]?\d*){1}$/',$s); //整数和小数和正负数
        return preg_match('/^\s*[\-\+]?(\d*[\.]?\d+|\d+[\.]?\d*){1}(e[\-\+]?\d+)?\s*$/',$s); //整数和小数和正负数和指数
    }
}
```