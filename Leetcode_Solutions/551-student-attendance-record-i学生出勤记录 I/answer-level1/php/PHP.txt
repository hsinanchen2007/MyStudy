时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function checkRecord($s) {
        $a = true;
        $b = true;
        $tmp = 0;

        for ($i = 0, $length = strlen($s); ($i < $length) && $a && $b; $i++) {
            if ($s[$i] == 'A' && ++$tmp > 1) {
                $a = false;
            } elseif ($s[$i] == 'L' && isset($s[$i + 1]) && $s[$i + 1] == 'L' && isset($s[$i + 2]) && $s[$i + 2] == 'L') {
                $b = false;
            }
        }

        return $a && $b;
    }
}
```