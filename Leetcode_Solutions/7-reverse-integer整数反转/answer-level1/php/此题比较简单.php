### 解题思路
此处撰写解题思路
很简单的代码，保留符号反转数值，然后做好溢出判断
### 代码

```php
class Solution
{

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x)
    {
        $sign = '';
        if ($x < 0) {
            $sign = '-';
        }
        $x = abs($x);
        $x = strrev($x);
        $x = intval($x);

        if ($x > pow(2,31) - 1 || intval('-' . $x) < pow(-2,31)) {
            $x = 0;
            $sign = '';
        }

        return $sign . $x;
    }
}
```