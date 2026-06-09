### 解题思路
首先确定范围和保存符号（默认是正数）
判断数字是否小于0，小于零则去掉符号，并且保存符号
使用系统函数strrev()反转后，拼接符号
转化为数字，简单判断是否在范围后即可返回


### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        $max = pow(2, 31);
        $min = pow(-2, 31);
        $ext = '';
        
        if ($x < 0){
            $x = substr($x, 1);
            $ext = '-';
        }

        $str = strrev($x);
        $str = $ext.$str;
        
        $number = intval($str);
        if ($number>$max || $number<$min || $number == 0){
            return 0;
        }

        return $number;
    }
}
```