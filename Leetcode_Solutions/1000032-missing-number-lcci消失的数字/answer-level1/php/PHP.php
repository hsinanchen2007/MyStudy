时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function missingNumber($nums) {
        $count = count($nums);
        $sum = $count * ($count + 1) / 2;

        for ($i = 0; $i < $count; $i++) {
            $sum -= $nums[$i];
        }

        return $sum;
    }
}
```