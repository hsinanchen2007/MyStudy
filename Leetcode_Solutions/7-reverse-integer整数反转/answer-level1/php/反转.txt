### 解题思路
1 取绝对值进行反转
2 判断符号  -
3 相乘去掉0
### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        $str=abs(strrev($x));//绝对值反转
        $z = ($x < 0) ? -1 : 1;//判断符号
        $number = $z * intval($str);//判断是否增加-，以及去掉0
        if ($number < - pow(2,31) or $number > (pow(2,31)-1)) {
            return 0;
        }
        return $number;
    }
}
```