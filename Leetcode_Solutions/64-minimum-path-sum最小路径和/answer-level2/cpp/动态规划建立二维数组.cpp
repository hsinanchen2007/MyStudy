```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        vector<int> row(grid[0].size() + 1, 0);
        vector<vector<int> > opt(grid.size() + 1, row);
        // 初始化
        for (int i = 0; i < opt[0].size(); ++i)
        {
            opt[0][i] = 0;
        }
        for (int i = 0; i < opt.size(); ++i)
        {
            opt[i][0] = 0;
        }
        // 初始化内层
        for (int i = 1; i < opt[0].size(); ++i)
        {
            opt[1][i] = opt[1][i - 1] + grid[0][i - 1];
        }
        for (int i = 1; i < opt.size(); ++i)
        {
            opt[i][1] = opt[i - 1][1] + grid[i - 1][0];
        }
        // dp
        for (int i = 2; i < opt.size(); ++i)
        {
            for (int j = 2; j < opt[0].size(); ++j)
            {
                opt[i][j] = min(opt[i - 1][j] + grid[i - 1][j - 1], opt[i][j - 1] + grid[i - 1][j - 1]);
            }
        }
        return opt[grid.size()][grid[0].size()];
    }
};
```
