### 解题思路
请参考注释和代码

### 代码
 /**
     * 使用动态规划求解
     * 关键是找到 dp table
     * <p>
     * 初始化dp，令dp[0][1] = ""，dp[1][0] = ""，可以看作是如下的一张表
     * 其中行和列分别代表两个字符串（以题目中到horse和ros为例）
     * <p>
     *       ''    r      o      s
     * ''    0     1      2      3
     * h    1
     * o    2
     * r    3
     * s    4
     * e    5
     * <p>
     * 对于上方这边表，可以认为
     * 第一行 dp[0][...]，从'' 到 ''，需要insert 0 次；到 r 需要insert 1 次；... 到s，需要 insert 3 次
     * 第一列 dp[...][0]，从'' 到 ''，需要delete 0 次；从h到''，需要delete 1 次；从 o 到 '' 需要delete 2 次；...以此类推
     * <p>
     * 那么状态转移方程就有：
     * <p>
     * 如果word1[i] == word2[j]，那么dp[i][j] = dp[i-1][j-1]
     * 如果word1[i] != word2[j]，那么dp[i][j] = Min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1])+1
     * <p>
     * 如下所示：
     * <p>
     *      ''    r      o      s
     * ''   0     1      2      3
     * h    1     1      2      3
     * o    2     2      1      2
     * r    3     2      2      2
     * s    4     3      3      2
     * e    5     4      4      3
     *
     * @param word1
     * @param word2
     * @return
     */
```java
class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int[][] dp = new int[m + 1][n + 1];
        // 处理第1行（因为第0行是字符串）
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        // 处理第0列（因为第0列也是字符串）
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        // 循环求解
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                // 如果word1[i] == word2[j]，那么dp[i][j] = dp[i-1][j-1]
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 如果word1[i] != word2[j]，那么dp[i][j] = Min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1])+1
                    dp[i][j] = Math.min(Math.min(
                            dp[i - 1][j] + 1,
                            dp[i][j - 1] + 1),
                            dp[i - 1][j - 1] + 1
                    );
                }
        // 返回矩阵中最后的元素
        return dp[m][n];
    }
}
```