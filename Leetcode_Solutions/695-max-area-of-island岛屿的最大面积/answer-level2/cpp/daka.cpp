```
class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int func(vector<vector<int>>& grid, int r, int c, int& rows, int& cols){
        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0)
            return 0;
        
        grid[r][c] = 0;
        int ans = 1;
        
        for(int i = 0; i < 4; i++)
            ans += func(grid, r+dir[i][0], c+dir[i][1], rows, cols);
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        int ans = 0, counter = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1)
                    counter = func(grid, i, j, rows, cols);
                ans = std::max(counter, ans);
            }
        }
        return ans;
    }
};
```
