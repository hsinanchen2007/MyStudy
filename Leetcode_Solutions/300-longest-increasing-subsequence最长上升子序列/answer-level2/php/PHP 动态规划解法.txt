### 解题思路

1. 定义 dp 数组，dp[i] 表示遍历到当前下标时最长上升子序列的长度
2. base case，如果数组不为空，遍历到每个位置，其最小值为 1
3. 状态转移方程

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function lengthOfLIS($nums) {
        $len = count($nums);
        if ($len <= 1) return $len;

        // // dp 数组的含义，表示  [0,...,i] 子串的 LIS，所以最后返回 max(dp) 即可
        $dp = array_fill(0, $len, 1);
        for ($i = 1; $i < $len; ++$i) {
            // i 是当前下标，j 是比 i 小的所有下标
            for ($j = 0; $j < $i; ++$j) {
                if ($nums[$j] < $nums[$i]) {
                    $dp[$i] = max($dp[$i], $dp[$j] + 1);
                }
            }
        }

        return max($dp);
    }                                 
}
```