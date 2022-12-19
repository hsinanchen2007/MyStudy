### 解题思路
和上一题类似，换汤不换药
递推公式为dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];

### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int n = grid.size(), m = grid[0].size();
        vector<long> tmp(m, grid[0][0]);
        vector<vector<long>> dp(n, tmp);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(i == 0 && j == 0) continue;
                int val1 = i > 0? dp[i-1][j]: INT_MAX;
                int val2 = j > 0? dp[i][j-1]: INT_MAX;
                dp[i][j] = min(val1, val2) + grid[i][j];
            }
        }
        return dp.back().back();
    }
};
```

###结果
执行用时 : 16 ms , 在所有 C++ 提交中击败了 21.68% 的用户 
内存消耗 : 9.2 MB , 在所有 C++ 提交中击败了 100.00% 的用户