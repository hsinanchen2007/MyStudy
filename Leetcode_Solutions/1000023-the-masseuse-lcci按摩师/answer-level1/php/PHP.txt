时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function massage($nums) {
        $count = count($nums);

        if ($count == 0) {
            return 0;
        }

        $a = 0;
        $b = $nums[0];

        for ($i = 1; $i < $count; $i++) {
            $tmp1 = $a > $b ? $a : $b;
            $tmp2 = $a + $nums[$i];
            $a = $tmp1;
            $b = $tmp2;
        }

        return $a > $b ? $a : $b;
    }
}
```