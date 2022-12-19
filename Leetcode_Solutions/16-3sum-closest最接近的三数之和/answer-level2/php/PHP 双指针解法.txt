与三数之和解法类似


```php
class Solution
{

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function threeSumClosest($nums, $target)
    {
        sort($nums);
        $len = count($nums);
        $distance = PHP_INT_MAX;
        $ans = null;
        for ($i = 0; $i < $len - 2; ++$i) {
            $left = $i + 1;
            $right = $len - 1;
            while ($left < $right) {
                $sum = $nums[$left] + $nums[$right] + $nums[$i];
                $diff = $sum - $target;
                if ($sum == $target) {
                    return $sum;
                } elseif ($sum > $target) {
                    while ($left < $right && $nums[$right - 1] == $nums[$right]) {
                        $right--;
                    }
                    $right--;
                } else {
                    while ($left < $right && $nums[$left + 1] == $nums[$left]) {
                        $left++;
                    }
                    $left++;
                }

                if (abs($diff) < $distance) {
                    $distance = abs($diff);
                    $ans = $sum;
                }
            }
        }
        return $ans;
    }
}
```
