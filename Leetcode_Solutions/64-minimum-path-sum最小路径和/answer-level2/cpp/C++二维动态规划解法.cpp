### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
    /*dp
    1 4 5
    2 7 6
    6 8 7
    */
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
        dp[0][0] = grid[0][0];
        for (int i=1; i<grid.size(); i++) dp[i][0] = grid[i][0] + dp[i-1][0];
        for (int j=1; j<grid[0].size(); j++) dp[0][j] = grid[0][j] + dp[0][j-1];
        for (int i=1; i<grid.size(); i++)
            for (int j=1; j<grid[0].size(); j++)
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        return dp[grid.size()-1][grid[0].size()-1];
    }
};
```