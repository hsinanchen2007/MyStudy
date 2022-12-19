### 解题思路
终止条件 leftSum + rightSum + $nums[$i] = array_sum($nums)
即 leftSum * 2 + $nums[$i] = array_sum($nums)

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function pivotIndex($nums) {
        $length = count($nums);
        // 终止条件 leftSum + rightSum + $nums[$i] = array_sum($nums)
        // 即 leftSum * 2 + $nums[$i] = array_sum($nums)
        $sum = array_sum($nums);
        $leftSum = 0;
        for ($i = 0; $i < $length; ++$i) {
            if ($leftSum * 2 + $nums[$i] == $sum) {
                return $i;
            }
            $leftSum += $nums[$i];
        }

        return -1;
    }
}
```