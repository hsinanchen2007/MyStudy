### 解题思路
这道题目和背包问题很像。
DP可以是一个这样的一个二维数组: DP[i][j]表示使用前i个硬币种类达成j的价值的硬币最小数目。这个思路可以从背包问题从0种物品到全部物品的逼近中获取灵感。
所以最后DP[coins.len()][amount]代表了使用全部的硬币种类，达到amount的价值的最小的数目。
对于DP的起点DP[0][0]不使用任何硬币达成0的价值是base case。
然后状态转移方程是 DP[i][j] = min(DP[i][j], DP[i][j - coin[i]] + 1)
当然我们可以发现，状态转移方程中并不存在跨行的状态转移 所以我们可以把第一个index 全部约掉。

### 代码

```rust
impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        // dp[m]: minimum number of coins to reach amount value
        // dp[m] = min(dp[m - coins[i]] + 1, dp[m])
        // initilize d[[coins[i]]] = 1;
        if amount == 0 {
            return 0;
        }
        let mut dp = vec![amount + 1; amount as usize + 1];
        dp[0] = 0;

        for i in 0..coins.len() {
            for m in coins[i]..amount+1 {
                dp[m as usize] = dp[m as usize].min(dp[(m - coins[i]) as usize] + 1);
            }
        }

        let res = if dp[amount as usize] > amount {-1} else {dp[amount as usize]};
        res
    }
}
```