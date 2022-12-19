
### dfs

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
        for(int j = 0; j < grid[0].size(); j++)
            if(grid[i][j] == 1)       res = max(res,dfs(grid,i,j));         //更新最大面积
        return res;
    }

    int dfs(vector<vector<int>>& grid,int i,int j){
        if( i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1)
            return 0;
        grid[i][j] = -1;        //防止重复访问，置为-1
        return 1 + dfs(grid,i-1,j) + dfs(grid,i+1,j) + dfs(grid,i,j-1) + dfs(grid,i,j+1);           //上下左右
    }
    
};
```