### 解题思路
设置几个标志位
- 从开始没有符号没有数字时，忽略空格，若遇见非空格，非符号则结束循环
- 有了符号后，后面要紧跟数字，遇见其他情况结束循环
- 有了数字后，后面要紧跟数字，遇见其他情况结束循环
- 判断最终值范围

### 代码

```php
class Solution {

    /**
     * @param String $str
     * @return Integer
     */
    function myAtoi($str) {
        $str = trim($str);
        $strList = str_split($str);
        $allow = ['1','2','3','4','5','6','7','8','9','0',' ', '-', '+'];
        $z = 1;
        $hasNumber = false;
        $hasZ = false;
        $number = '';
        foreach ($strList as $v) {
            if (in_array($v, $allow, true)) {
                if ($hasNumber) {
                    if ($v === ' ' or $v == '-'or $v == '+') {
                        echo 2;
                        break;
                    }
                    $number .= $v;
                } else {
                    if (!$hasZ) {
                        if ($v == '-') {
                            $z = -1;
                            $hasZ = true;
                        }
                        if ($v == '+') {
                            $z = 1;
                            $hasZ = true;
                        }
                    } elseif ($v === ' ' or $v === '+' or $v === '-') {
                        echo 1;
                        break;
                    }
                    if ($v !== ' ' && $v !='-'&& $v !='+') {
                        $number .= $v;
                        $hasNumber = true;
                    }
                }
                
            } else {
                break;
            }
        }
        $number *= $z;
        if ($number > pow(2,31)-1) {
            return pow(2,31) -1;
        } else if( $number < -pow(2,31)) {
            return -pow(2,31);
        }
        return $number;
    }
}
```