`dp[i][j]`表示`(i,j)`格子是否可达，可达表示1，不可达表示0，通过遍历每个格子从而推出每个格子是否可达。

而(i,j)是否可达，由两个方面决定：
1. 一者，如果格子`(i,j)`可达，那么格子`(i-1,j)`或`(i,j-1)`其中之一必定可达
2. 二者，i和j的数位和小于k。

所以在i和j的数位和小于k的前提条件下应有如下方程：

```math
dp[i][j] = dp[i-1][j] or dp[i][j-1];
```

代码如下：
```java
class Solution {
    public int movingCount(int m, int n, int k) {
        int[][] dp = new int[m][n];
        dp[0][0] = 1;

        int cnt = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                boolean flag = false;
                if (i-1 >= 0 && dp[i-1][j] == 1) flag = true; // 左方向可达
                if (j-1 >= 0 && dp[i][j-1] == 1) flag = true; // 上方向可达
                if (sum(i) + sum(j) <= k && flag) {
                    dp[i][j] = 1; // 如果i,j的数位之和小于k 且 左方向或者上方向可达 则(i,j)可达
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    public int sum(int n) {
        int ans = 0;
        while (n != 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
}
```