### 代码

```java
class Solution {
    public int waysToStep(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 4;

        int MOD = 1000000007;
        long[] dp = new long[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        
        for(int i = 4; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
        }
        return (int) dp[n];
    }
}
```

```java
class Solution {
    public int waysToStep(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 4;

        int MOD = 1000000007;
        long f1 = 1, f2 = 2, f3 = 4, f = 0;
        for(int i = 4; i <= n; i++) {
            f = (f1 + f2 + f3) % MOD; f1 = f2; f2 = f3; f3 = f;
        }
        return (int) f;
    }
}
```