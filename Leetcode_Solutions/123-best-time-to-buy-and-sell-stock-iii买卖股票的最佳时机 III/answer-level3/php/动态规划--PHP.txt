### 解题思路
动态规划

算法
- 状态, dp[i][j][0]表示第i天进行了j次交易，目前不持有股票；dp[i][j][1]表示第i天进行了j次交易，目前持有股票.
- 状态转移方程
1、当天进行了j次交易，并不持有股票的最大收益为两种情况取大者：一、前一天交易了j次本身也不持有股票；二、前一天进行了j次交易，并持有股票，今天卖了。交易发生在当天，所以前一天的交易次数是j, 不是j - 1。
```
dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
```

2、当天进行了j次交易，并持有股票的最大收益为两种情况取大者：一、前一天交易了j次本身持有股票；二、前一天进行了最多j - 1次交易，并不持有股票，当天买入了。当天还能买入，说明之前交易次数没有达到j次。
```
dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
```


注意：个人理解，状态转移方程中交易以买入为准，买入后交易增加一次，卖出交易次数不变。所以下面的状态转移方程不对：
```
dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] + prices[i]);
dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i]);
```

### 性能
执行用时 :68 ms, 在所有 PHP 提交中击败了13.33%的用户
内存消耗 :45 MB, 在所有 PHP 提交中击败了41.18%的用户

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
        $deal_count = 2;

        for ($i = 0; $i < count($prices); $i++) {
            for ($j = $deal_count; $j >= 1; $j--) {
                if ($i == 0) {
                    $dp[$i][$j][0] = 0;
                    $dp[$i][$j][1] = -$prices[$i];
                    continue;
                }
                $dp[$i][$j][0] = max($dp[$i - 1][$j][0], $dp[$i - 1][$j][1] + $prices[$i]);
                $dp[$i][$j][1] = max($dp[$i - 1][$j][1], $dp[$i - 1][$j - 1][0] - $prices[$i]);
            }
        }

        return $dp[count($prices) - 1][$deal_count][0];
    }
}
```

说明：j从后往前和从前往后都可以。

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-w-5/](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-w-5/)