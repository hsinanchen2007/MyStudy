### 解题思路
没啥好说的，取模真的神奇

### 代码

```java
class Solution {
    public int fib(int n) {
        if (n == 0) return 0;
        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
            dp[i] %= (1e9 + 7);
        }
        return dp[n];
    }
}
```