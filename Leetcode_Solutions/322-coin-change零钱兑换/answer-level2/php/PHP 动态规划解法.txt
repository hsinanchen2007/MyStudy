### 代码

```php
class Solution {
    function coinChange($coins, $amount) {
        if ($amount == 0) return 0;
        // 初始化结果，最坏情况，都是 1
        $dp = array_fill(1, $amount, $amount + 1);
        for ($i = 1; $i <= $amount; ++$i) {
            foreach ($coins as $coin) {
                if ($coin > $i) continue;
                // 状态转移方程
                $dp[$i] = min($dp[$i], $dp[$i - $coin] + 1);
            }
        }
        return $dp[$amount] > $amount ? -1 : $dp[$amount];
    }
}
```