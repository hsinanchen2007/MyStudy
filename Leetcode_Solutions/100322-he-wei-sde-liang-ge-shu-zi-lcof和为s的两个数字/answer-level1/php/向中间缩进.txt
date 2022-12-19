### 解题思路
因为有序，可前后同时遍历判断。逐步向中间缩进

### 代码

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
        if (count($nums) < 2) {
            return [];
        }
        $i = 0;
        $j = count($nums) - 1;
        while ($i < $j) {
            $sum = $nums[$i] + $nums[$j];
            if ($sum > $target) {
                $j--;
            } else if ($sum < $target) {
                $i++;
            } else {
                return [$nums[$i], $nums[$j]];
            }
        }
        return [];
    }
}
```