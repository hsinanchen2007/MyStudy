```php
function maxProfit($prices, $fee)
    {
        // dp 
        // dp[day][k][0 or 1]
        // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] -fee)
        // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])

        $len = count($prices);
        if ($len <= 1) {
            return 0;
        }

        $dp_i_0 = 0;
        $dp_i_1 = PHP_INT_MIN;
        for ($i = 0; $i < $len; ++$i) {
            $temp = $dp_i_0;
            $dp_i_0 = max($dp_i_0, $dp_i_1 + $prices[$i] - $fee);
            $dp_i_1 = max($dp_i_1, $temp - $prices[$i]);
        }
        return $dp_i_0;
    }
```
