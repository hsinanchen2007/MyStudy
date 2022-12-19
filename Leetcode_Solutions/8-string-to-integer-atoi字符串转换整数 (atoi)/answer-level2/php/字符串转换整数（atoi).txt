### 解题思路

### 代码

```php
class Solution {

    /**
     * @param String $str
     * @return Integer
     */
     /**
     1.定义一个变量确定他是正数还是负数
     2.循环去判断下个下标值是否为整数
     */
    function myAtoi($str) {
        if (!$str) return 0;
        $str = trim($str);
        $res = 0;
        $sign = 1;  //标示他是正整数
        $start = $str[0];
        if ($start == '+') {
            $start = 1;
        } elseif ($start == '-') {
            $start = 1;
            $sign = -1;
        } else {
            $start = 0;
        }
        for ($i = $start; $i < strlen($str); $i++) {
            if (!is_numeric($str[$i])) {
                return $sign * $res;
            }
            $res = $res * 10 + $str[$i];
            if ($res >= pow(2, 31)) {
                if ($sign > 0) {
                    return pow(2, 31) - 1 * $sign;
                }
                return pow(2, 31) * $sign;
            }
        }
        return $res*$sign;
    }
}
```