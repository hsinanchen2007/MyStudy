### 解题思路
直接上dp。

### 代码

```java
class Solution {
    public int fib(int n) {

        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
            dp[i] %= 1000000007;
        }

        return dp[n];
    }
}
```

执行用时 :0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :35.7 MB, 在所有 Java 提交中击败了100.00%的用户