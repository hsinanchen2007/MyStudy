### 解题思路
将数字转为字符，翻转后再转为数字，拼接正负号，确定有没有超过边界，超过返0没有继续返回

### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        $strList = str_split(strval($x));
        $str = '';
        foreach ($strList as $v) {
            $str = $v.$str;
        }
        $z = ($x < 0) ? -1 : 1;
        $number = $z * intval($str);
        if ($number < - pow(2,31) or $number > (pow(2,31)-1)) {
            return 0;
        }
        return $number;
    }
}
```