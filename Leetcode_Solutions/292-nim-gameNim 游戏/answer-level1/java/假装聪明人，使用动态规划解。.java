虽然内存会超限：
```java
class Solution {
    public boolean canWinNim(int n) {

        if (n <= 3) {
            return true;
        }

        // 定义状态：dp[i] 表示石头总数是 i 时，我先手能否取胜
        boolean[] dp = new boolean[n+1];

        // 定义初始值
        dp[0] = true;
        dp[1] = true;
        dp[2] = true;
        dp[3] = true;

        // 定义状态转移方程： dp[i] = !dp[i-1] || !dp[i-2] || !dp[i-3]
        for (int i = 4; i <= n; i++) {
            dp[i] = !dp[i-1] || !dp[i-2] || !dp[i-3];
        }

        return dp[n];
    }
}
```