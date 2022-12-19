### 解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return Boolean
     */
    function isIsomorphic($s, $t) {
        for ($i = 0; $i < strlen($s); $i++) {
            if (strpos($s, $s[$i]) != strpos($t, $t[$i])) return false;
        }

        return true;
    }
}
```