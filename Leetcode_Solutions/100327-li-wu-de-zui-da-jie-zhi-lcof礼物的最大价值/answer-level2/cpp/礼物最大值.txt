### 解题思路
动态规划问题，先写好状态转移方程。此处dp[i][j]表示第i,j个格子上最大的礼物价值和
dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i][j]
然后计算每个格子的最大礼物价值，从下到上计算，首先最左和最上的格子是固定的，先算出来。
还可以简化成一维数组减少空间占用
### 代码

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        dp[0][0]=grid[0][0];
        for(int i = 1;i<cols;i++)
            dp[0][i] = dp[0][i-1]+grid[0][i];
        for(int j = 1;j<rows;j++)
            dp[j][0] = dp[j-1][0]+grid[j][0];
        for(int i=1;i<rows;i++){
            for (int j =1;j<cols;j++){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[rows-1][cols-1];
    }
};
```