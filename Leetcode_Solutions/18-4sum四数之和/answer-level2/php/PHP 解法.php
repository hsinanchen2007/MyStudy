在三数之和的基础上，再进行一次遍历

```php
class Solution
{

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[][]
     */
    function fourSum($nums, $target)
    {
        sort($nums);
        $ans = [];
        $len = count($nums);
        for ($i = 0; $i < $len - 3; ++$i) {
            $arr = array_slice($nums, $i + 1);
            $threeSum = $this->threeSum($arr, $target - $nums[$i]);
            if ($threeSum) {
                foreach ($threeSum as $val) {
                    array_unshift($val, $nums[$i]);
                    $ans[implode(',', $val)] = $val;
                }
            }
        }

        return array_values($ans);
    }
    private function threeSum($nums, $target)
    {
        $ans = [];
        $len = count($nums);
        for ($i = 0; $i < $len - 2; ++$i) {
            $left = $i + 1;
            $right = $len - 1;
            while ($left < $right) {
                $sum = $nums[$i] + $nums[$left] + $nums[$right];
                if ($sum == $target) {
                    $key = sprintf('%d_%d_%d', $nums[$i], $nums[$left], $nums[$right]);
                    $ans[$key] = [$nums[$i], $nums[$left], $nums[$right]];
                    $left++;
                    $right--;
                } elseif ($sum < $target) {
                    while ($left < $right && $nums[$left + 1] == $nums[$left]) {
                        $left++;
                    }
                    $left++;
                } else {
                    while ($left < $right && $nums[$right - 1] == $nums[$right]) {
                        $right--;
                    }
                    $right--;
                }
            }
        }
        return array_values($ans);
    }
}
```
