时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function smallerNumbersThanCurrent($nums) {
        $count = count($nums);
        $hash = [];

        for ($i = 0; $i < $count; $i++) {
            $hash[$nums[$i]] = ($hash[$nums[$i]] ?? 0) + 1;
        }

        for ($i = 0; $i <= 100; $i++) {
            if (isset($hash[$i])) {
                if (isset($sum)) {
                    $tmp = $hash[$i];
                    $hash[$i] = $sum;
                    $sum += $tmp;
                } else {
                    $sum = $hash[$i];
                    $hash[$i] = 0;
                }
            }
        }

        for ($i = 0; $i < $count; $i++) {
            $nums[$i] = $hash[$nums[$i]];
        }

        return $nums;
    }
}
```