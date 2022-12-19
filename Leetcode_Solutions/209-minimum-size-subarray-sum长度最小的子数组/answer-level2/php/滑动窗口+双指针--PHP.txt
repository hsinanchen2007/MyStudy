### 解题思路
滑动窗口+双指针

### 代码

```php
class Solution {

    /**
     * @param Integer $s
     * @param Integer[] $nums
     * @return Integer
     */
    function minSubArrayLen($s, $nums) {
        $sum = 0;
        $min = PHP_INT_MAX;

        $front = $rear = 0;
        while ($rear < count($nums)) {
            $sum += $nums[$rear];

            while ($sum >= $s) {
                $min = min($min, $rear - $front + 1);
                $sum -= $nums[$front];
                $front++;
            }

            $rear++;
        }

        return $min == PHP_INT_MAX ? 0 : $min;
    }
}
```

### 性能
执行用时 :16 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :18.8 MB, 在所有 PHP 提交中击败了10.00%的用户

### 算法复杂度
-- 时间复杂度 O(N)
-- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/minimum-size-subarray-sum/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-43/](https://leetcode-cn.com/problems/minimum-size-subarray-sum/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-43/)