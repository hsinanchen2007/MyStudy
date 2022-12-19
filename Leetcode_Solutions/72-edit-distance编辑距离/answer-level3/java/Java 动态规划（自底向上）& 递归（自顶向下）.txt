动态规划（自底向上）
思路：
定义二维数组dp[i][j]，表示word1[0,i]与word2[0,j]之间的最少步数
dp[i-1][j-1]表示替换操作
dp[i-1][j]表示删除操作
dp[i][j-1]表示插入操作

DP方程：
if (word1[i] == word2[j]) dp[i][j] = dp[i - 1][j - 1] // 什么都不操作
else dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])); // 替换、删除、插入取最小值

```java
class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        if (m == 0 || n == 0) return m + n;

        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) dp[i][0] = i; // or dp[i][0] = dp[i - 1][0] + 1;
        for (int j = 0; j <= n; j++) dp[0][j] = j; // or dp[0][j] = dp[0][j - 1] + 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = Math.min(Math.min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
        return dp[m][n];
    }
}
```

递归+记忆化（自顶向下）
思路一样，但个人觉得可能用递归理解起来会更友好一点。
```java
class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        return minDistanceHelper(word1, word2, m, n, new int[m + 1][n + 1]);
    }

    public int minDistanceHelper(String word1, String word2, int i, int j, int[][] memo) {
        if (i == 0 || j == 0) return i + j;
        if (memo[i][j] > 0) return memo[i][j];

        if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
            return memo[i][j] = minDistanceHelper(word1, word2, i - 1, j - 1, memo);
        } else {
            return memo[i][j] = 1 + Math.min(Math.min(
                minDistanceHelper(word1, word2, i - 1, j - 1, memo),
                minDistanceHelper(word1, word2, i - 1, j, memo)
            ), minDistanceHelper(word1, word2, i, j - 1, memo));
        }
    }
}
```