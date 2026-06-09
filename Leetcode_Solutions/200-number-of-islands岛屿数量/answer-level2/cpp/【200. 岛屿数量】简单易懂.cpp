## 思路
### 代码
```
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {        
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();
        int c = 0;
        vector<vector<bool>> visited(row, vector<bool>(col));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++c;
                    dfs(grid, visited, i, j);
                }                
            }
        }
        return c;
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {        
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0' || visited[row][col]) {
            return;
        }
        visited[row][col] = true;
        dfs(grid, visited, row - 1, col);
        dfs(grid, visited, row + 1, col);
        dfs(grid, visited, row, col - 1);
        dfs(grid, visited, row, col + 1);
    }
};
```
#### 另一种写法
优化空间复杂度，访问过就重置值为 0。
```c++
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {        
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();
        int c = 0;        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    ++c;
                    dfs(grid, i, j);
                }                
            }
        }
        return c;
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col) {        
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') {
            return;
        }
        grid[row][col] = '0';
        dfs(grid, row - 1, col);
        dfs(grid, row + 1, col);
        dfs(grid, row, col - 1);
        dfs(grid, row, col + 1);
    }
};
```

