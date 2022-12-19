
## 解题思路

比较每个字符首次出现的位置是否相同

## 代码
```php
class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return Boolean
     */
    function isIsomorphic($s, $t) {
        $len = strlen($s);
        if($len != strlen($t)) {
            return false;
        }
        for($i = 0; $i < $len; $i++) {
            if(strpos($s, $s[$i]) !== strpos($t, $t[$i])) return false;
        }
        return true;
    }
}
```
