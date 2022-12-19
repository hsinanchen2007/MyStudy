### 解题思路
定义二维数组dp[i][j]保存取当前位置grid(i,j)后可以获取的最大价值
dp[i][j] = max(dp[i-1][j],dp[i][j-1])+grid[i][j]
由上面可以观察到j只和当前位置j以及前一个位置j-1相关，因此可以将二位dp化简为一维dp
dp[j] = max(dp[j],dp[j-1]) + grid[i][j]
解决了一部分空间

### 代码

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        vector<int> dp(grid[0].size(), 0);
        dp[0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); ++i) {
            dp[i] = dp[i-1] + grid[0][i];
        }
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (!j) {
                    dp[j] += grid[i][j];
                    continue;
                }
                dp[j] = max(dp[j-1], dp[j]) + grid[i][j];
            }
        }
        return dp[grid[0].size()-1];
    }
};
```