```
class Solution {
   public int waysToChange(int n) {
        double[] dp = new double[n + 1];
        dp[0] = 1;
        int[] coins = {1, 5, 10, 25};
        for (int coin : coins) {
            for (int i = 1; i <= n; i++) {
                if (i >= coin) {
                    dp[i] = (dp[i] + dp[i - coin]) % 1000000007;
                }
            }
        }
        return (int) dp[n];
    }
}
```
