### 解题思路
动态规划：dp[i] = dp[i - 1] + dp[i - 2]
初始化dp[0] = dp[1] = 1
思想：到达第i层的途径要么是从前面两层一步过来，要么从前面一层一步过来，因此有上面的转移方程。

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }
        int dpLow = 1;
        int dpHigh = 1;
        for (int i = 2; i <= n; i++) {
            int tmp = dpLow + dpHigh;
            dpLow = dpHigh;
            dpHigh = tmp;
        }

        return dpHigh;
    }
}
```