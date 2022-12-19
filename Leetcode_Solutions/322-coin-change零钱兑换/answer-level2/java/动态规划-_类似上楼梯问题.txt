### 解题思路
动态规划DP


### 代码

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        if (coins.length == 0 || coins == null || amount <= 0)
            return 0;

        int[] dp = new int[amount + 1];
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            dp[i] = 9999;
            for (int j = 0; j < coins.length; j++) {
                if (i >= coins[j]) {
                    dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
}
```