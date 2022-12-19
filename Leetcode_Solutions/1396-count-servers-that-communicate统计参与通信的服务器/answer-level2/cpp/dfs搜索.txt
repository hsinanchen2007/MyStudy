class Solution {
public:

    int dfs(vector<vector<int> >& grid, int x, int y)
    {
        int row = grid.size();
        int col = grid[0].size();
        if(x < 0 || x > row - 1 || y < 0 || y > col - 1) return 0;
        if(grid[x][y] != 1) return 0;

        grid[x][y] = -1;
        int ans = 1;

        // 搜索整列
        for(int i = 0; i < row; i++)
        {
            ans += dfs(grid, i, y);
        }

        // 搜索整行
        for(int i = 0; i < col; i++)
        {
            ans += dfs(grid, x, i);
        }

        return ans;
    }

    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    int ret = dfs(grid, i, j);
                    if(ret > 1) ans += ret;
                }
            }
        }

        return ans;
    }
};