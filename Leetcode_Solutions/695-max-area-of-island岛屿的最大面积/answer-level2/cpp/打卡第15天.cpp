学习中
```
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        if(!grid.size() || !grid[0].size()) return result;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    result = max(result, area(grid,i,j));
                }
            }
        }
        return result;


    }
    int area(vector<vector<int>>& grid, int r, int c){
        if (! (r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c] == 1 ))
        return 0;
        grid[r][c] = 2;
    
        return 1 + area(grid, r+1,c) + area(grid, r-1, c) +
                area(grid, r, c+1) + area(grid, r, c-1);

    }
};
```
