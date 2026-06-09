### 解题思路
动态规划：
先初始化dp的第一行与第一列；
分以下两种情况讨论：
（1）当word1[i - 1] = word2[j - 1]的时候，dp[i][j] = dp[i - 1][j - 1]；
（2）当word1[i - 1] != word2[j - 1]的时候：
- 当进行插入操作的时候，为dp[i - 1][j] + 1；
- 当进行删除操作的时候，为dp[i][j - 1] + 1；
- 当进行替换操作的时候，为dp[i - 1][j - 1] + 1；
- 最终的结果为以上三种操作的最小值：dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1)。
![捕获.JPG](https://pic.leetcode-cn.com/aa3be29bd126e0a33c79170a27ad8c70feccbf3dffacba769865784ad6eb113f-%E6%8D%95%E8%8E%B7.JPG)

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));  // 插入、删除、替换
                }
            }
        }
        return dp[m][n];
    }
};
```