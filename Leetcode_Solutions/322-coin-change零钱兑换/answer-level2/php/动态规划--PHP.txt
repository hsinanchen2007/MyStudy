### 解题思路
动态规划

算法：
- 状态dp[i]表示凑齐金额i需要的最少硬币数量。
- 状态转移方程
```
dp[i] = min(dp[i], dp[i - coins[i]] + 1)
```
注意：为什么是i - coins[i]？
以coins = [1, 2, 5], amount = 11为例
我们要求组成11的最少硬币数，可以考虑组合中的最后一个硬币分别是1，2，5的情况，比如

最后一个硬币是1的话，最少硬币数应该为【组成10的最少硬币数】+ 1枚（1块硬币）
最后一个硬币是2的话，最少硬币数应该为【组成9的最少硬币数】+ 1枚（2块硬币）
最后一个硬币是5的话，最少硬币数应该为【组成6的最少硬币数】+ 1枚（5块硬币）


- 初始化
dp[0]  = 0
dp[i] = amount + 1

### 代码

```php
class Solution {

    /**
     * @param Integer[] $coins
     * @param Integer $amount
     * @return Integer
     */
    function coinChange($coins, $amount) {
        $dp = [];

        $dp[0] = 0;
        for ($i = 1; $i <= $amount; $i++) {
            $dp[$i] = $amount + 1;
            foreach ($coins as $coin) {
                if ($i >= $coin) $dp[$i] = min($dp[$i], $dp[$i - $coin] + 1);
            }
        }

        return $dp[$amount] > $amount ? -1 : $dp[$amount];
    }
}
```

### 性能
执行用时 :312 ms, 在所有 PHP 提交中击败了86.21%的用户
内存消耗 :15.1 MB, 在所有 PHP 提交中击败了100.00%的用户

### 算法复杂度
- 时间复杂度 O(M * N)
- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/coin-change/solution/zi-di-xiang-shang-dong-tai-gui-hua-by-pendygg/](https://leetcode-cn.com/problems/coin-change/solution/zi-di-xiang-shang-dong-tai-gui-hua-by-pendygg/)
[https://leetcode-cn.com/problems/coin-change/solution/dong-tai-gui-hua-tao-lu-xiang-jie-by-wei-lai-bu-ke/](https://leetcode-cn.com/problems/coin-change/solution/dong-tai-gui-hua-tao-lu-xiang-jie-by-wei-lai-bu-ke/)