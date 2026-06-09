时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return String
     */
    function findTheDifference($s, $t) {
        $hash = [];

        for ($i = 0, $length = strlen($t); $i < $length; $i++) {
            $hash[$t[$i]] = ($hash[$t[$i]] ?? 0) + 1;
        }

        for ($i = 0, $length = strlen($s); $i < $length; $i++) {
            if (--$hash[$s[$i]] == 0) {
                unset($hash[$s[$i]]);
            }
        }

        foreach ($hash as $key => $value) {
            return $key;
        }
    }
}
```