```
class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        if((i<0) || (j<0) || (i>=grid.size()) || (j>=grid[0].size()) || (grid[i][j] == 0))
            return 0;

        grid[i][j] = 0;
        int nums = 1;
        nums += dfs(grid, i+1, j);
        nums += dfs(grid, i-1, j);
        nums += dfs(grid, i, j+1);
        nums += dfs(grid, i, j-1);
        return nums;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int res = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                res = max(res, dfs(grid, i , j));
            }

        }
        return res;
    }
};
```
