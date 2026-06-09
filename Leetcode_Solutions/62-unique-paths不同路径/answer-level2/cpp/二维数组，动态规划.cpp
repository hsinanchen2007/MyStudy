### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        //dp[i][j] = dp[i-1][j]+dp[i][j-1]，上方和左方不同路径数相加
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
```