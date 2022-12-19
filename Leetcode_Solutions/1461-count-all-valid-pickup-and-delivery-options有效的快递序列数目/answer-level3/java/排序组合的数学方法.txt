```
public int countOrders(int n) {
        int mod = 1000000007;
        long[] dp = new long[n + 1];
        dp[1] = 1L;
        for(int i = 2; i <= n; i++) {
            long x = 2 * (i - 1) + 1;
            dp[i] = dp[i-1] * ((x + 1) * (x) / 2);
            dp[i] %= mod;
        }
        
        return (int) dp[n];
    }
```
