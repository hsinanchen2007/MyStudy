### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
    int LocaArea = 0;
    int MaxArea = 0;
public:

    void Dfs(vector<vector<int>>& grid, vector<vector<bool>>& IsIsland, int x, int y){
        if(x == grid.size() || y == grid[0].size() || y < 0 || x < 0 || grid[x][y] == 0 || IsIsland[x][y] == true)
            return;
        ++LocaArea;
        IsIsland[x][y] = true;
        Dfs(grid, IsIsland, x + 1, y);
        Dfs(grid, IsIsland, x, y + 1);
        Dfs(grid, IsIsland, x, y - 1);
        Dfs(grid, IsIsland, x - 1, y);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> IsIsland(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1)
                    Dfs(grid, IsIsland, i, j);
                MaxArea = max(MaxArea, LocaArea);
                LocaArea = 0;
            }
        }
        return MaxArea;
    }
};
```