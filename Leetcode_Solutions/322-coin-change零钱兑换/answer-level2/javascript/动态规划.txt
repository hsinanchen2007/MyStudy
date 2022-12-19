### 解题思路
用动态规划可以解。

dp[n] 表示用 coins 的硬币集，最少花费多少步能到达 n
dp[n] = min(dp[n-c0], dp[n-c1], ..., dp[n-c(n-1)])


### 代码

```javascript
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, amount) {
    const dp = new Array();
    dp.push(0);
    for (let i = 0; i < amount; ++i) {
        dp.push(amount + 1);
    }
    for (let i = 1; i  < amount + 1; ++i) {
        for (let j = 0; j < coins.length; ++j) {
            if (i >= coins[j]) {
                dp[i] = Math.min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
};
```

### 复杂度
- 时间复杂度 O(S*N)
- 空间复杂度 O(N)