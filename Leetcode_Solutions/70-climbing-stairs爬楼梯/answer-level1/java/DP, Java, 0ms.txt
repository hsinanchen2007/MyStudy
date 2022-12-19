### 解题思路
1. 状态有 走一步 和 走两步, i-1, i-2;
2. 当前状态 是从 之前的 两种选择 累加后的结果, 状态转移方程 f(x) = f(x-1) + f(x-2)

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;

        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        int cost;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
}
```