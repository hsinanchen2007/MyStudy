```
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        return dfs(0, 0, grid);
    }
    
    bool dfs(int x, int y, vector<vector<int>>& grid) {
        //cout<<x<<";"<<y<<endl;
        if(x<0 || y <0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1) return false;
        if(x == grid.size()-1 && y == grid[0].size()-1) return true;
        int val = grid[x][y];
        //cout<<val<<endl;
        grid[x][y] = -1;
        bool ret1 = false;
        bool ret2 = false;
        if(val == 1) {
            if(y-1>=0 && (grid[x][y-1] == 1 || grid[x][y-1] == 4 || grid[x][y-1] == 6 ))
                ret1 = dfs(x, y-1, grid);
            if(y+1<grid[0].size() && (grid[x][y+1] == 1 || grid[x][y+1] == 3 || grid[x][y+1] == 5 ))
                ret2 = dfs(x, y+1, grid);
        } else if(val == 2) {
            if(x-1>=0 && (grid[x-1][y] == 2 || grid[x-1][y] == 3 || grid[x-1][y] == 4 ))
                ret1 = dfs(x-1, y, grid);
            if(x+1<grid.size() && (grid[x+1][y] == 2 || grid[x+1][y] == 5 || grid[x+1][y] == 6 ))
                ret2 = dfs(x+1, y, grid);
        } else if(val == 3) {
            if(y-1>=0 && (grid[x][y-1] == 1 || grid[x][y-1] == 4 || grid[x][y-1] == 6))
                ret1 = dfs(x, y-1, grid);
            if(x+1<grid.size() && (grid[x+1][y] == 2 || grid[x+1][y] == 5 || grid[x+1][y] == 6 ))
                ret2 = dfs(x+1, y, grid);
        } else if(val == 4) {
            if(y+1<grid[0].size() && (grid[x][y+1] == 1 || grid[x][y+1] == 3 || grid[x][y+1] == 5 ))
                ret1 = dfs(x, y+1, grid);
            if(x+1<grid.size() && (grid[x+1][y] == 2 || grid[x+1][y] == 5 || grid[x+1][y] == 6 ))
                ret2 = dfs(x+1, y, grid);
        } else if(val == 5) {
            if(y-1>=0 && (grid[x][y-1] == 1 || grid[x][y-1] == 4 || grid[x][y-1] == 6 ))
                ret1 = dfs(x, y-1, grid);
            if(x-1>=0 && (grid[x-1][y] == 2 || grid[x-1][y] == 3 || grid[x-1][y] == 4 ))
                ret2 = dfs(x-1, y, grid);
        } else if(val == 6) {
            if(y+1<grid[0].size() && (grid[x][y+1] == 1 || grid[x][y+1] == 3 || grid[x][y+1] == 5 ))
                ret1 = dfs(x, y+1, grid);
            if(x-1>=0 && (grid[x-1][y] == 2 || grid[x-1][y] == 3 || grid[x-1][y] == 4 ))
                ret2 = dfs(x-1, y, grid);
        }
        return ret1 || ret2;
    }
};
```
