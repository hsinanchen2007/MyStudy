```php
function maxProfit($k, $prices)
    {
        $len = count($prices);
        if ($k <= 0 || $len <= 1) {
            return 0;
        }
        if ($k > $len / 2) {
            // 相当于 k = infinity
            $dp_i_0 = 0;
            $dp_i_1 = PHP_INT_MIN;
            for ($i = 0; $i < $len; ++$i) {
                $temp = $dp_i_0;
                $dp_i_0 = max($dp_i_0, $dp_i_1 + $prices[$i]);
                $dp_i_1 = max($dp_i_1, $temp - $prices[$i]);
            }

            return $dp_i_0;
        }

        // dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i])
        // dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] + prices[i])
        $dp = array_fill(0, $len, array_fill(0, $k, array_fill(0, 2, null)));
        for ($i = 0; $i < $len; ++$i) {
            for ($j = 0; $j < $k; ++$j) {
                if ($i - 1 == -1) {
                    $dp[$i][$j][0] = max(0, PHP_INT_MIN + $prices[$i]);
                    $dp[$i][$j][1] = max(PHP_INT_MIN, -$prices[$i]);
                } else {
                    $dp[$i][$j][0] = max($dp[$i - 1][$j][0], $dp[$i - 1][$j][1] + $prices[$i]);
                    if ($j - 1 == -1) {
                        $dp[$i][$j][1] = max($dp[$i - 1][$j][1], -$prices[$i]);
                    } else {
                        $dp[$i][$j][1] = max($dp[$i - 1][$j][1], $dp[$i - 1][$j - 1][0] - $prices[$i]);
                    }
                }
            }
        }

        return $dp[$len - 1][$k - 1][0];
    }
```
