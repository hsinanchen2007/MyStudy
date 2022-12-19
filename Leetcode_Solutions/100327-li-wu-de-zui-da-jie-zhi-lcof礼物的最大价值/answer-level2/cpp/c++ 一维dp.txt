```c++
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        std::vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[j] = grid[i][j] + std::max(dp[j], j > 0 ? dp[j - 1] : 0);
            }
        }
        
        return dp[n - 1];
    }
};
```