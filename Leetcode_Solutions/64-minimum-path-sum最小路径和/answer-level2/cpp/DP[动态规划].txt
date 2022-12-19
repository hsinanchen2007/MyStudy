### 解题思路
求得状态转移方程：
dp[i][j] = grid[i-1][j-1] + min(dp[i+1][j], dp[i][j+1]);
求得初始状态：
dp[i][j] = grid[i-1][j-1];

### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
        for (int i = grid.size(); i > 0; i--) {
            for (int j = grid[0].size(); j > 0; j--) {
                if (i == grid.size() && j == grid[0].size()) {
                    dp[i][j] = grid[i-1][j-1];
                    continue;
                }
                int count1 = INT_MAX;
                int count2 = INT_MAX;
                if (i + 1 <= grid.size()) {
                    count1 = dp[i + 1][j];
                }
                if (j + 1 <= grid[0].size()) {
                    count2 = dp[i][j + 1];
                }
                dp[i][j] = grid[i-1][j-1] + min(count1, count2);
            }
        }
        return dp[1][1];
    }
};
```