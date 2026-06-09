时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String $s1
     * @param String $s2
     * @return Boolean
     */
    function CheckPermutation($s1, $s2) {
        $length = strlen($s1);

        if ($length != strlen($s2)) {
            return false;
        }

        $hash = [];

        for ($i = 0; $i < $length; $i++) {
            $hash[$s1[$i]] = ($hash[$s1[$i]] ?? 0) + 1;
        }

        for ($i = 0; $i < $length; $i++) {
            if (!isset($hash[$s2[$i]]) || --$hash[$s2[$i]] < 0) {
                return false;
            }
        }

        return true;
    }
}
```