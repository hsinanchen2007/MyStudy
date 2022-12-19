### 解题思路
一道简单的DP问题。直接上DP~~

### 代码

```java
class Solution {
    public int numWays(int n) {

        if (n == 0) return 1;
        if (n == 1) return 1;

        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
            dp[i] %= 1000000007;
        }

        return dp[n];
    }
}
```
执行用时 :0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :36 MB, 在所有 Java 提交中击败了100.00%的用户