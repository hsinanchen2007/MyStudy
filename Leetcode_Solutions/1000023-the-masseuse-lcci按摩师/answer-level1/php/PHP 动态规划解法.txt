比较基础的动态规划，与股票问题类似。

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function massage($nums) {
        $n = count($nums);
        if ($n == 0) return 0;
        $dp = array_fill(0, $n, array_fill(0, 2, 0));
        $dp[0][0] = 0;
        $dp[0][1] = $nums[0];
        for ($i = 1; $i < $n; ++$i) {
            $dp[$i][0] = max($dp[$i - 1][0], $dp[$i - 1][1]);
            $dp[$i][1] = max($dp[$i - 1][0] + $nums[$i], $dp[$i - 1][1]);
        }

        return max($dp[$n - 1][0], $dp[$n - 1][1]);
    }
}
```