### 解题思路
访问过的节点置0，代替hash统计，减少空间复杂度

### 代码

```cpp
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0) return 0;
        grid[r][c] = 0;
        return 1+dfs(grid,r-1,c)+dfs(grid,r+1,c)+dfs(grid,r,c-1)+dfs(grid,r,c+1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;    
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
               max_area = max(max_area, dfs(grid,i,j));
        return max_area;
    }
};
```