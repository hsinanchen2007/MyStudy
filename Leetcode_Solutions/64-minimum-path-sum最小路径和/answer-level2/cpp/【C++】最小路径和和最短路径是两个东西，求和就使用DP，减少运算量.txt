```
/*
* Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
* Description: i love leetcode
* Author: Nicolas
* Create: 2019/09/30
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        if (grid.empty()) {
            return 0;
        }
        if (grid.at(0).empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid.at(0).size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i - 1 == 0) {
                    dp[i][j] = dp[i][j - 1] + grid[i - 1][j - 1];
                } else if (j - 1 == 0) {
                    dp[i][j] = dp[i - 1][j] + grid[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
```
