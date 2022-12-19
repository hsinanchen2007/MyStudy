**C++DFS递归，思想很简单，但需要注意很多问题**
* 防止回环产生，所以不允许往左上方走
* 每次记录上一次的方向(1,2,3,4为上下左右)
* 注意到达条件，只需到达该点即可，对方向无要求，所以需要对5单独处理
```
class Solution {
public:
    bool dfs(int x, int y, vector<vector<int>>& grid,int lastL){
        // printf("%d %d\n",x, y);
        if(x == grid.size() && y == grid[0].size()-1)
            return true;
        if(x == grid.size()-1 && y == grid[0].size())
            return true;
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return false;
        switch (grid[x][y]){
            case(1): 
                if(lastL == 3)
                    return dfs(x, y+1, grid, 3);
                if(lastL == 4)
                    return dfs(x, y-1, grid, 4);
                else
                    return false;
            case(2): 
                if(lastL == 1)
                    return dfs(x+1, y, grid, 1);
                if(lastL == 2)
                    return dfs(x-1, y, grid, 2);
                else
                    return false;
            case(3): 
                if(lastL == 3)
                    return dfs(x+1, y, grid, 1);
                else
                    return false;
            case(4): 
                if(lastL == 2)
                    return dfs(x, y+1, grid, 3);
                if(lastL == 4)
                    return dfs(x+1, y, grid, 1);
                else
                    return false;
            case(5): 
                if((lastL == 1 || lastL == 3) && (x == grid.size()-1 && y == grid[0].size()-1))
                    return true;
                if(lastL == 1) 
                    return dfs(x, y-1, grid, 4);
                if(lastL == 3)
                    return dfs(x-1, y, grid, 2);
                else
                    return false;
            case(6): 
                if(lastL == 1)
                    return dfs(x, y+1, grid, 3);
                else
                    return false;
        }
        return false;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        switch (grid[0][0]) {
            case(1): return dfs(0, 1, grid, 3);
            case(2): return dfs(1, 0, grid, 1);
            case(3): return dfs(1, 0, grid, 1);
            case(4): return dfs(1, 0, grid, 1) || dfs(0, 1, grid, 3);
            case(5): return false;
            case(6): return dfs(0, 1, grid, 3);
        }
        return false;
    }
};
```

