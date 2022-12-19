### 解题思路
先将数字转为字符串，然后进行字符串反转，最后再转回数字

### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        $signed = '';
        $x = (string)$x;
        if ($x < 0) {
            $x = trim($x, '-');
            $signed = '-';
        }

        $new = '';
        for ($i = strlen($x) - 1; $i >= 0; $i--) {
            $new .= $x[$i];
        }

        $signed .= $new;
        $signed = intval($signed);

        if ($signed < -pow(2, 31) || $signed > pow(2, 31) - 1) {
            return 0;
        }

        return $signed;
    }
}
```