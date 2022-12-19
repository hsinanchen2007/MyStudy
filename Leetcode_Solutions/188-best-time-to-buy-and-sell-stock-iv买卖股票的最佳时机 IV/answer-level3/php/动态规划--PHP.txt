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
执行用时 :64 ms, 在所有 PHP 提交中击败了28.57%的用户
内存消耗 :57.2 MB, 在所有 PHP 提交中击败了57.14%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $k
     * @param Integer[] $prices
     * @return Integer
     */
    public function maxProfit($k, $prices) {
        if (empty($prices) || $k <= 0) return 0;

        // 交易次数过大，导致内存溢出。这里认为$k超过天数的一半就认为交易次数不限了，走买卖股票的最佳时机 II这个逻辑
        if ($k > (count($prices) / 2)) return $this->maxProfitInf($prices);

        $dp = [];

        for ($i = 0; $i < count($prices); $i++) {
            for ($j = $k; $j >= 1; $j--) {
                if ($i == 0) {
                    $dp[$i][$j][0] = 0;
                    $dp[$i][$j][1] = -$prices[$i];
                    continue;
                }
                $dp[$i][$j][0] = max($dp[$i - 1][$j][0], $dp[$i - 1][$j][1] + $prices[$i]);
                $dp[$i][$j][1] = max($dp[$i - 1][$j][1], $dp[$i - 1][$j - 1][0] - $prices[$i]);
            }
        }

        return $dp[count($prices) - 1][$k][0];
    }

    // 买卖股票，尽可能多的完成交易
    public function maxProfitInf($prices) {
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

说明：
- j从后往前和从前往后都可以。
- 买卖股票，尽可能多的完成交易说可参考：[salmonl-买卖股票最佳时机2题解](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/dong-tai-gui-hua-php-by-salmonl-10/)

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-w-5/](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-w-5/)