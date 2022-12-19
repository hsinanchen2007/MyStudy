### 解题思路
遍历所有格子。遇到一个陆地，就四处逛完和它相连的区域，把1都打掉，同时计数+1。然后继续遍历下一个格子。思路不难。

### 代码

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == '0') {
                    continue;
                }
                ++ result;
                this->markIslands(grid, i, j);
            }
        }
        return result;
    }

    void markIslands(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || x > grid.size() - 1 || y < 0 || y > grid[x].size() - 1 || grid[x][y] == '0') {
            return ;
        }
        grid[x][y] = '0';
        this->markIslands(grid, x+1, y);
        this->markIslands(grid, x, y+1);
        this->markIslands(grid, x-1, y);
        this->markIslands(grid, x, y-1);
    }
};
```