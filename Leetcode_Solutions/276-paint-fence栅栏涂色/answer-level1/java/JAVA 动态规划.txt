状态方程 dp[n] = dp[n - 2] * (k - 1) +  dp[n - 1] * (k - 1)
dp[n - 2] * (k - 1) ： 当前n的颜色与前一个fence的颜色相同
dp[n - 1] * (k - 1) ： 当前n的颜色与前一个fence的颜色不同， 因为不同，所以只有（k - 1）个
```
    public int numWays(int n, int k) {
        //dp[n] = dp[n - 2] * (k - 1) +  dp[n - 1] * (k - 1)
        int[] dp = new int[n + 1];
        if(n == 0)  return 0;
        if(n == 1)  return k;
        dp[1] = k;
        dp[2] = k * k;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 2] * (k - 1) + dp[i - 1] * (k - 1);
        }
        return dp[n];
    }
```
