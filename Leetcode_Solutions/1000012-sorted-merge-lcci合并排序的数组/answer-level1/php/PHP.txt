时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $A
     * @param Integer $m
     * @param Integer[] $B
     * @param Integer $n
     * @return NULL
     */
    function merge(&$A, $m, $B, $n) {
        $i = $m + $n - 1;
        $m -= 1;
        $n -= 1;

        while ($n >= 0) {
            if ($A[$m] > $B[$n]) {
                $A[$i] = $A[$m];
                $m--;
            } else {
                $A[$i] = $B[$n];
                $n--;
            }
            $i--;
        }

        return $A;
    }
}
```