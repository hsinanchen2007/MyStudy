```
class Solution {
    public int waysToChange(int n) {
        int[] dp = new int[n+1];
        dp[0] = 1;
        int mod = 1000000007;
        int[] coins = new int[] {1, 5, 10, 25};
        for (int coin: coins) {
            for (int t=1; t<=n; t++) {
                if (t >= coin)
                    dp[t] = (dp[t] + dp[t-coin]) % mod;
            }        
        }
        return dp[n];
    }
}
```