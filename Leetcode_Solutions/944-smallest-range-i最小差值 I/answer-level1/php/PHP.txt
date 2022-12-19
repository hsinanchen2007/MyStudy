时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $A
     * @param Integer $K
     * @return Integer
     */
    function smallestRangeI($A, $K) {
        $count = count($A);

        if ($count == 0) {
            return 0;
        }

        $max = $A[0];
        $min = $A[0];

        for ($i = 1; $i < $count; $i++) {
            if ($max < $A[$i]) {
                $max = $A[$i];
            }
            if ($min > $A[$i]) {
                $min = $A[$i];
            }
        }

        $max -= $K;
        $min += $K;

        $num = $max - $min;

        return $num > 0 ? $num : 0;
    }
}
```