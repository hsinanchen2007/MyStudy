### 解题思路
1-3个别处理
n=4开始，从小算到大。
转移方程：dp[i] = Math.max(dp[j]*dp[i-j], dp[i]);

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        if (n < 2) {
            return 0;
        }
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= i/2; j++) {
                dp[i] = Math.max(dp[j]*dp[i-j], dp[i]);
            }
        }
        return dp[n];
    }
}
```