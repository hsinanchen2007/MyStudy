### 解题思路
动态规划

算法:
- 状态 dp[i][0]表示第i天不持有股票的最大收益，dp[i][1]表示第i天持有股票的最大收益。
- 状态转移方程: 
1、前一天不持有股票; 或者前一天持有股票，今天卖出, 卖出的时候减去交易费。取大的
dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
2、前一天持有股票；或者前一天不持有股票，今天买入。取大的
dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
- 初始化
$dp[0][0] = 0;
$dp[0][1] = -prices[0];

说明：参考资料说买入或卖出的时候减去交易费都想，实测卖出的时候减可以通过，否则通不过。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $prices
     * @param Integer $fee
     * @return Integer
     */
    function maxProfit($prices, $fee) {
        if (empty($prices)) return 0;

        $dp = [];

        $dp[0][0] = 0;
        $dp[0][1] = -$prices[0];
        for ($i = 1; $i < count($prices); $i++) {
            $dp[$i][0] = max($dp[$i - 1][0], $dp[$i - 1][1] + $prices[$i] - $fee);
            $dp[$i][1] = max($dp[$i - 1][0] - $prices[$i], $dp[$i - 1][1]);
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