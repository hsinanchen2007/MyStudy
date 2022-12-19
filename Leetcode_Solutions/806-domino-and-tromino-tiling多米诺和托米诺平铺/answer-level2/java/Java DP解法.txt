### 代码

```java
class Solution {
    public int numTilings(int N) {
        int mod = 1000000007;
        if (N <= 2) return N;
        long[] dp = new long[N + 1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= N; i ++) {
            dp[i] = ((2 * dp[i - 1]) % mod + dp[i - 3]) % mod;
        }
        return (int)dp[N];
    }
}
```