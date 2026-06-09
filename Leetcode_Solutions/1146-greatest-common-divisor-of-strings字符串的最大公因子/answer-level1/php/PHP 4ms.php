### 解题思路
此处撰写解题思路
本题就是求解公因子的正确思路，把两个字符串进行相减，求得最后一个字符串为空的情况下，剩余字符串
### 代码

```php
class Solution {

    /**
     * @param String $str1
     * @param String $str2
     * @return String
     */
    function gcdOfStrings($str1, $str2) {
        //return $str2;
        while ($str1 && $str2) {
            //return $str2;
            $len1 = strlen($str1);
            $len2 = strlen($str2);
            if ($len1 > $len2) {
                $tmp1 = substr($str1, 0, $len2);
                if ($tmp1 != $str2) {
                    return '';
                }
                $str1 = substr($str1, $len2);
                if ($str1 == '') {
                    return $str2;
                }
            } elseif ($len1 == $len2) {
                if ($str1 == $str2) {
                    return $str2;
                }
                return '';
                //return $str2;
            } else {
                $tmp2 = substr($str2, 0, $len1);
                if ($tmp2 != $str1) {
                    return '';
                }
                $str2 = substr($str2, $len1);
                if ($str2 == '') {
                    return $str1;
                }
            }
            
        }
        return '';
    }
}
```