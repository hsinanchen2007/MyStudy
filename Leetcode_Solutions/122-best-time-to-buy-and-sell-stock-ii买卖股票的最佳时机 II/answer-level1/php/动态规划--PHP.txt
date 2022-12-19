### 解题思路
动态规划

算法:
- 状态 dp[i][0]表示第i天不持有股票的最大收益，dp[i][1]表示第i天持有股票的最大收益。
- 状态转移方程: 
1、前一天不持有股票; 或者前一天持有股票，今天卖出。取大的
dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
2、前一天持有股票；或者前一天不持有股票，今天买入。取大的
dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
- 初始化
$dp[0][0] = 0;
$dp[0][1] = -prices[0];

注意：买卖股票的最佳时机交易一次的区别，主要在状态转移方程上的差异，具体可参考[这里](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/dong-tai-gui-hua-php-by-salmonl-9/)。

### 性能
执行用时 :28 ms, 在所有 PHP 提交中击败了6.90%的用户
内存消耗 :25.9 MB, 在所有 PHP 提交中击败了5.59%的用户

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
        for ($i = 1; $i < count($prices); $i++) {
            $dp[$i][0] = max($dp[$i - 1][0], $dp[$i - 1][1] + $prices[$i]);
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