### 解题思路
动态规划

算法:
- 状态 dp[i][0]表示第i天不持有股票的最大收益，dp[i][1]表示第i天持有股票的最大收益。
- 状态转移方程: 
1、前一天不持有股票; 或者前一天持有股票，今天卖出。取大的
dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
2、前一天持有股票；或者前2天不持有股票，今天买入。取大的
dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
- 初始化
$dp[0][0] = 0;
$dp[0][1] = -$prices[0];
$dp[1][0] = max($dp[0][0], $dp[0][1] + $prices[1]);
$dp[1][1] = max(-$prices[0], -$prices[1]);

注意：
状态转移方程一定要是前2天的。
初始化就套用状态转移方程，不存在的状态就为0，比如i = 0 dp[i - 1][0]

### 性能
执行用时 :8 ms, 在所有 PHP 提交中击败了83.33%的用户
内存消耗 :16.6 MB, 在所有 PHP 提交中击败了14.29%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        if (empty($prices)) return 0;

        $dp = [];

        $dp[0][0] = 0;
        $dp[0][1] = -$prices[0];
        $dp[1][0] = max($dp[0][0], $dp[0][1] + $prices[1]);
        $dp[1][1] = max(-$prices[0], -$prices[1]);
        for ($i = 2; $i < count($prices); $i++) {
            $dp[$i][0] = max($dp[$i - 1][0], $dp[$i - 1][1] + $prices[$i]);
            $dp[$i][1] = max($dp[$i - 1][1], $dp[$i - 2][0] - $prices[$i]);
        }

        return $dp[count($prices) - 1][0];
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-w-5/](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-w-5/)