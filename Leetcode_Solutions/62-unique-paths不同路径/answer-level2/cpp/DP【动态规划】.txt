### 解题思路
状态转移方程：
dp[n][m] = dp[n+1][m] + dp[n][m+1]
初始化变量：
dp[n][m] = 1;
开始DP既可。
### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = n; i > 0; i--) {
            for (int j = m; j > 0; j--) {
                if (i == n && j == m) {
                    dp[n][m] = 1;
                    continue;
                }
                int downNum = 0;
                int rightNum = 0;
                if (i + 1 <= n) {
                    downNum = dp[i + 1][j];
                }
                if (j + 1 <= m) {
                    rightNum = dp[i][j + 1];
                }
                dp[i][j] = downNum + rightNum;
            }
        }
        return dp[1][1];
    }
};
```