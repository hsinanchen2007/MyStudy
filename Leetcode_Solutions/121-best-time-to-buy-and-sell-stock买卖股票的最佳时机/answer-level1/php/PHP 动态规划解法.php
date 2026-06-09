```php
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        // dp
        // 状态 dp[day][k][0 or 1] 某一天，操作次数，空仓或持有
        // 状态转移方程 dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
        // dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
        // 边界条件
        // dp[-1][k][0] = 0, dp[-1][k][1] = PHP_INT_MIN
        // dp[i][0][0] = 0, dp[i][0][1] = PHP_INT_MIN
        // max k = 1
        // 简化
        // dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
        // dp[i][1][1] = max(dp[i-1][1][1], - prices[i])
        // k 不影响状态转移方程，降维
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
        // dp[i][1] = max(dp[i-1][1], - prices[i])
        // 边界条件
        // dp[-1][0] = 0, dp[-1][1] = PHP_INT_MIN
        // dp[i][0] = 0, dp[i][1] = PHP_INT_MIN
        $len = count($prices);
        if ($len <= 1) {
            return 0;
        }
        // 初始值，i=-1
        $dp_i_0 = 0;
        $dp_i_1 = PHP_INT_MIN;
        for ($i = 0; $i < $len; ++$i) {
            $dp_i_0 = max($dp_i_0, $dp_i_1 + $prices[$i]);
            $dp_i_1 = max($dp_i_1, -$prices[$i]);
        }

        return $dp_i_0;
    }
}
```
