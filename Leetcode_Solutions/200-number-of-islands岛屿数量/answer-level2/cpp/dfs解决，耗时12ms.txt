### 解题思路
dfs查找联通岛屿

### 代码

```cpp
class Solution {
public:
vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
void dfs(vector<vector<char>>& grid, int row, int col, char color) {
    grid[row][col] = color;
    int R = grid.size();
    int C = grid[0].size();
    for (int i = 0; i < dir.size();i++) {
        int nr = row + dir[i][0];
        int nc = col + dir[i][1];
        if (nr >=0 && nr < R && nc >=0 && nc <C && grid[nr][nc] == '1') {
            dfs(grid, nr, nc, color);
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int R = grid.size();
    if(R == 0) {
        return 0;
    }
    int C = grid[0].size();
    int step = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == '1') {
                step++;
                char color = '2';
                dfs(grid, i, j, color);
            }
        }
    }
    return step;
}
};
```