参考 labuladong 的题解

```php
class Solution
{

    /**
     * @param Integer[] $piles
     * @return Boolean
     */
    function stoneGame($piles)
    {
        $count = count($piles);
        $dp = array_fill(0, $count, array_fill(0, $count, [0, 0]));
        // base case
        for ($i = 0; $i < $count; ++$i) {
            $dp[$i][$i] = [$piles[$i], 0];
        }

        // 斜着遍历
        for ($l = 2; $l <= $count; ++$l) {
            for ($i = 0; $i <= $count - $l; ++$i) {
                $j = $l + $i - 1;
                $left = $piles[$i] + $dp[$i + 1][$j][1];
                $right = $piles[$j] + $dp[$i][$j - 1][1];
                // 状态转移方程
                if ($left > $right) {
                    $dp[$i][$j][0] = $left;
                    $dp[$i][$j][1] = $dp[$i + 1][$j][0];
                } else {
                    $dp[$i][$j][0] = $right;
                    $dp[$i][$j][1] = $dp[$i][$j - 1][0];
                }
            }
        }

        return $dp[0][$count - 1][0] > $dp[0][$count - 1][1];
    }
}
```
