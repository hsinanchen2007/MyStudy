```
class Solution {
    public int change(int amount, int[] coins) {
        int[] dp;
        int i, j;

        dp = new int[amount+1];
        dp[0] = 1;
        for(i = 0; i < coins.length; i++){
            for(j = 1; j < amount + 1; j++)
                dp[j] = dp[j] + (j < coins[i] ? 0 : dp[j-coins[i]]);
        }
        return dp[amount];
    }
}
```
