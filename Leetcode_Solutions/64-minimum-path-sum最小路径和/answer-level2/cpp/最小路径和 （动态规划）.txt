```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int j = 1; j < grid[0].size(); j++)//第一行
            grid[0][j] += grid[0][j-1];
        for(int i = 1; i < grid.size(); i++)//第一列
            grid[i][0] += grid[i-1][0];   
        for(int i = 1 ; i < grid.size(); i++)//行
        {
            for(int j = 1 ; j < grid[0].size(); j++)//列
            {
                 grid[i][j] += min(grid[i-1][j] , grid[i][j-1]);
            }
        }
       return grid[grid.size()-1][grid[0].size()-1];
    }
};
```
