### 解题思路
题目较为常规,维护一个二维DP数组,一维代表子串的起始位置,一维代表需要的分割天数,整体表示将子串分割为相应天数所能得到的最小难度

### 代码

```java
class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {
        int[][] dp = new int[jobDifficulty.length][d + 1];

        dp[dp.length - 1][1] = jobDifficulty[jobDifficulty.length - 1];

        for (int i = dp.length - 2; i >= 0; i--) {
            dp[i][1] = Math.max(dp[i + 1][1], jobDifficulty[i]);
        }

        for (int i = 2; i <= d; i++) {
            for (int j = 0; j < jobDifficulty.length; j++) {
                int maxDifficulty = jobDifficulty[j];
                dp[j][i] = Integer.MAX_VALUE / 4;

                for (int t = j; t < jobDifficulty.length; t++) {
                    maxDifficulty = Math.max(maxDifficulty, jobDifficulty[t]);
                    dp[j][i] = Math.min(dp[j][i], maxDifficulty + (t + 1 < dp.length ? dp[t + 1][i - 1] : Integer.MAX_VALUE / 4));
                }
            }
        }

        return dp[0][d] >= Integer.MAX_VALUE / 4 ? -1 : dp[0][d];
    }
}
```