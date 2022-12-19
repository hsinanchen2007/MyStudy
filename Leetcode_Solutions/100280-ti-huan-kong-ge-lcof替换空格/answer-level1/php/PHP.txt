时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function replaceSpace($s) {
        $S = '';

        for ($i = 0, $length = strlen($s); $i < $length; $i++) {
            $S .= $s[$i] == ' ' ? '%20' : $s[$i];
        }

        return $S;
    }
}
```