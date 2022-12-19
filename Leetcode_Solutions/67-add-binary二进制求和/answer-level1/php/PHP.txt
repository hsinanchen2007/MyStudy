### 解题思路
此处撰写解题思路
考虑的点其实就是进位的处理，包括
1. 两数相加时进位
2. 最后一位是否有进位
### 代码

```php
class Solution {

    /**
     * @param String $a
     * @param String $b
     * @return String
     */
    function addBinary($a, $b) {
        if ($a == '0') {
            return $b;
        } elseif ($b == '0') {
            return $a;
        }
        $lenA = strlen($a) - 1;
        $lenB = strlen($b) - 1;
        $str = '';
        $flag = 0;
        while ($lenA >= 0 || $lenB >= 0) {
            $valueA = $lenA < 0 ? 0 : (int)$a[$lenA];
            $valueB = $lenB < 0 ? 0 : (int)$b[$lenB];
            if (($value = $valueA + $valueB + $flag) == 2) {
                $flag = 1;
                $value = 0;
            } elseif ($value == 3) {
                $flag = 1;
                $value = 1;
            } else {
                $flag = 0;
            }
            $str = ((string)$value) . $str;
            $lenA --;
            $lenB --;
        }
        if ($flag) {
            $str = '1' . $str;
        }
        return $str;
    }
}
```