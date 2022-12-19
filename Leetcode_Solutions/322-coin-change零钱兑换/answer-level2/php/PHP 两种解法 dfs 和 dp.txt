```
class Solution
{

    public $min = PHP_INT_MAX;
    /**
     * dfs 解法
     */
    function coinChange1($coins, $amount)
    {
        if (empty($coins)) return -1;
        if ($amount == 0) return 0;
        sort($coins);
        if ($amount < $coins[0]) return -1;
        $sum = 0;
        $this->dfs($coins, $amount, $sum, count($coins) - 1);
        return $this->min === PHP_INT_MAX ? -1 : $this->min;
    }

    function dfs($coins, $amount, $sum, $index)
    {
        if ($index < 0 || ($sum + $amount / $coins[$index] >= $this->min)) return;
        if ($amount == 0) {
            $this->min = min($this->min, $sum);
            return;
        }
        for ($i = $index; $i >= 0; --$i) {
            if ($amount < $coins[$i]) continue;
            $this->dfs($coins, $amount - $coins[$i], $sum + 1, $i);
        }
    }

    /**
     * 动态规划
     */
    function coinChange($coins, $amount)
    {
        $dp = array_fill(1, $amount + 1, $amount + 1);
        $dp[0] = 0;
        for ($i = 1; $i <= $amount; $i++) {
//            for ($j = 0; $j < count($coins); $j++) {
//                if ($coins[$j] <= $i) {
//                    $dp[$i] = min($dp[$i], $dp[$i - $coins[$j]] + 1);
//                }
//            }
            foreach ($coins as $coin) {
                if ($coin <= $i) {
                    $dp[$i] = min($dp[$i], $dp[$i - $coin] + 1);
                }
            }
        }
        return $dp[$amount] > $amount ? -1 : $dp[$amount];
    }
}
```