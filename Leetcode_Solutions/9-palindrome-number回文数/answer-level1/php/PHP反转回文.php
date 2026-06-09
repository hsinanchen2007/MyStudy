### 解题思路
直接反转匹配即可

### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome($x) {
        $s = strval($x);

        $len = strlen($s);

        $r_s = '';
        for($i = $len - 1;$i >= 0;$i--) {
            $r_s .= $s[$i];
        }

        if($r_s == $s) {
            return true;
        } else {
            return false;
        }
    }
}
```