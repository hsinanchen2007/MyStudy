```php
function maxProfit($prices)
    {
        // dp
        // dp[day][k][0 or 1]
        // dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
        // dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i])
        $len = count($prices);
        if ($len <= 1) {
            return 0;
        }
        $dp = array_fill(0, $len, array_fill(0, 2, array_fill(0, 2, null)));
        for ($k = 0; $k < 2; ++$k) {
            for ($i = 0; $i < $len; ++$i) {
                if ($i - 1 == -1) {
                    $dp[$i][$k][0] = max(0, PHP_INT_MIN + $prices[$i]);
                    $dp[$i][$k][1] = max(PHP_INT_MIN, 0 - $prices[$i]);
                } else {
                    $dp[$i][$k][0] = max($dp[$i - 1][$k][0], $dp[$i - 1][$k][1] + $prices[$i]);
                    if ($k - 1 == -1) {
                        $dp[$i][$k][1] = max($dp[$i - 1][$k][1], -$prices[$i]);
                    } else {
                        $dp[$i][$k][1] = max($dp[$i - 1][$k][1], $dp[$i - 1][$k - 1][0] - $prices[$i]);
                    }
                }
            }
        }
        return $dp[$len - 1][1][0];
    }
```
