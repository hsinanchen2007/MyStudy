```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function maxValue($grid) {
        $m = count($grid);
        if ($m == 0) return 0;
        $n = count($grid[0]);
        $dp = [];
        $dp[0][0] = $grid[0][0];
        //初始化dp
        for ($i = 1; $i < $m; $i++) {//第一列
            $dp[$i][0] = $dp[$i - 1][0] + $grid[$i][0];
        }
        for ($i = 1; $i < $n; $i++) {//第一行
            $dp[0][$i] = $dp[0][$i - 1] + $grid[0][$i];
        }
        for ($i = 1; $i < $m; $i++) {
            for($j = 1; $j < $n; $j++) {
                $dp[$i][$j] = max($dp[$i - 1][$j], $dp[$i][$j - 1]) + $grid[$i][$j];
            }
        }
        return $dp[$m - 1][$n - 1];
    }
}
```
