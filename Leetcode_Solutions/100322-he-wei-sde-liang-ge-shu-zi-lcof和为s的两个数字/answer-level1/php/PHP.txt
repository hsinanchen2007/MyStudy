时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $l = 0;
        $r = count($nums) - 1;

        while ($l < $r) {
            $sum = $nums[$l] + $nums[$r];
            if ($sum == $target) {
                return [$nums[$l], $nums[$r]];
            }
            $sum > $target ? $r-- : $l++;
        }
    }
}
```