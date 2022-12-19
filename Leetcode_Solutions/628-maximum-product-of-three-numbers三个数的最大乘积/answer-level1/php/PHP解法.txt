1. 取最大值时要判断数组是否有负数
2. 负数情况要两个最大负数相乘变正
3. 只考虑了负数情况即可
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maximumProduct($nums) {
        if (empty($nums)) {
            return 0;
        }
        $count = count($nums);
        sort($nums);
        $a = $nums[$count-1] * $nums[$count-2] * $nums[$count-3];
        $b = $nums[0] * $nums[1] * $nums[$count-1];
        return max($a,$b);
    }
}
```
