### 解题思路
动态规划解决   （关注微信公众号'码农黑板报'查看更多题解）
![image.png](https://pic.leetcode-cn.com/8e43b386005ab651514ed1a8f4d03520279b9097eb82dd0067d06da23e581ff4-image.png)


### 代码

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i == 0) {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                } else if (j == 0) {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};
```