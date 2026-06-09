时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maximumProduct($nums) {
        $min1 = 1001;
        $min2 = 1001;
        $max1 = -1001;
        $max2 = -1001;
        $max3 = -1001;

        foreach ($nums as $value) {
            if ($value <= $min1) {
                $min2 = $min1;
                $min1 = $value;
            } elseif ($value <= $min2) {
                $min2 = $value;
            }
            if ($value >= $max1) {
                $max3 = $max2;
                $max2 = $max1;
                $max1 = $value;
            } elseif ($value >= $max2) {
                $max3 = $max2;
                $max2 = $value;
            } elseif ($value >= $max3) {
                $max3 = $value;
            }
        }

        $tmp1 = $min1 * $min2 * $max1;
        $tmp2 = $max1 * $max2 * $max3;

        return $tmp1 > $tmp2 ? $tmp1 : $tmp2;
    }
}
```