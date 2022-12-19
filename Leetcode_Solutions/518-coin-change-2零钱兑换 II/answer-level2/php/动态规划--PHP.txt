### 解题思路
动态规划

算法
- 状态dp[i]
- 状态转移方程
dp[i] = dp[i] + dp[i - coins[i]]

### 代码

```php
class Solution {

    /**
     * @param Integer $amount
     * @param Integer[] $coins
     * @return Integer
     */
    function change($amount, $coins) {
        $dp = [];

        $dp[0] = 1;

        foreach ($coins as $coin) {
            for ($i = 1; $i <= $amount; $i++) {
                if ($i >= $coin) $dp[$i] = $dp[$i] + $dp[$i - $coin];
            }
        }

        return (int)$dp[$amount];
    }
}
```

### 性能
执行用时 :164 ms, 在所有 PHP 提交中击败了33.33%的用户
内存消耗 :15.3 MB, 在所有 PHP 提交中击败了100.00%的用户

### 算法复杂度
- 时间复杂度 O(M * N)
- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/coin-change-2/comments/37934](https://leetcode-cn.com/problems/coin-change-2/comments/37934)