

```php
class Solution
{

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target)
    {
        $count = count($nums);
        if ($count <= 0) {
            return [];
        }

        sort($nums);
        if ($target < reset($nums)) {
            return [];
        }

        $left = 0;
        $right = $count - 1;
        while ($left < $right) {
            $sum = $nums[$left] + $nums[$right];
            if ($sum == $target) {
                return [$nums[$left], $nums[$right]];
            } elseif ($sum < $target) {
                $left++;
            } else {
                $right--;
            }
        }

        return [];
    }
}
```