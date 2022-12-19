```php
function maxProfit($prices)
    {
        // dp
        // 状态 dp[day][k][0 or 1]
        // 状态转移方程 dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i])
        // dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
        // 边界条件
        // dp[-1][k][0] = 0, dp[-1][k][1] = PHP_INT_MIN
        // dp[-1][0][0] = 0, dp[-1][0][1] = PHP_INT_MIN
        // 简化， k 不限制次数，忽略其影响
        // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
        // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
        $len = count($prices);
        if ($len <= 1) {
            return 0;
        }
        $dp_i_0 = 0;
        $dp_i_1 = PHP_INT_MIN;
        for ($i = 0; $i < $len; ++$i) {
            $temp = $dp_i_0;
            $dp_i_0 = max($dp_i_0, $dp_i_1 + $prices[$i]);
            $dp_i_1 = max($dp_i_1, $temp - $prices[$i]);
        }

        return $dp_i_0;
    }
```
