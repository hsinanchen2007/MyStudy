class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        for (int i = grid.size() - 1; i >= 0; i--) 
        {
            for (int j = grid[0].size() - 1; j >= 0; j--) 
            {
                if(i == grid.size()- 1 && j != grid[0].size() - 1)
                    grid[i][j] = grid[i][j] +  grid[i][j + 1];//边界条件d第一行和最后一行
                else if(j == grid[0].size() - 1 && i != grid.size() - 1)
                    grid[i][j] = grid[i][j] + grid[i + 1][j];//边界条件第一列和最后一列
                else if(j != grid[0].size() - 1 && i != grid.size() - 1)
                    grid[i][j] = grid[i][j] + min(grid[i + 1][j],grid[i][j + 1]);//正常情况
            }
        }
        return grid[0][0];
        
    }
};
