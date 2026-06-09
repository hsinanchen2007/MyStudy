### 解题思路
无符号数字转数组，再反转数组，再加上符号

### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        $_x = $x;
        if($_x == 0) return 0;
        if($x < 0) $_x = abs($x);

        $r = array_reverse(str_split($_x));
        $num =  intval(implode('',$r));

        if($num > (pow(2,31)-1)) return 0;

        return $x > 0 ? $num : -$num;
    }
}
```