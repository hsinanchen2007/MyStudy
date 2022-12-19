### 解题思路
使用dp的时间复杂度为O（M*N)
先遍历第一层数据，算出在第一层挨个走下去每走到一个格子的总步数。
然后开始使用dp。
dp[i][j]=grid[i][j]+min(dp[i][j-1],dp[i-1][j])
处于节省内存的考虑，在原地修改。直接将dp[i][j]写入对于grid[i][j]
### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid[0].size();
        int m=grid.size();
        for(int i=1;i<n;i++)
            grid[0][i]+=grid[0][i-1];
        for(int i=1;i<m;i++)
        {
            grid[i][0]+=grid[i-1][0];
            for(int j=1;j<n;j++)
            {
                int mid= grid[i][j-1] < grid[i-1][j] ? grid[i][j-1] : grid[i-1][j];
                grid[i][j]+=mid;
            }
        }
        return grid[m-1][n-1];
    }
};
```