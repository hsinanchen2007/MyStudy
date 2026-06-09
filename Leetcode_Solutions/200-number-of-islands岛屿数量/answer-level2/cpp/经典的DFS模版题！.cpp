### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {

    const vector<vector<int>> DIRS = {
        {0, -1}, {-1, 0}, {0, 1}, {1, 0}  // 上，左，下，右
    };
    
    // DFS (Depth-First-Search) 深度优先搜索
    // 先尝试一条路径走到底... 直到黄河... 再走另一方向路径 (四个方向都要遍历过)
    void dfs(vector<vector<char>>& grid, int r, int c) {
        const int M = grid.size(), N = grid[0].size();
        if (r < 0 || r >= M || c < 0 || c >= N || grid[r][c] == '0')
            return;

        grid[r][c] = '0';
        for (auto &dir : DIRS)
            dfs(grid, r + dir[1], c + dir[0]);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        
        if (grid.empty()) return 0;

        const int M = grid.size(), N = grid[0].size();
        
        int ans = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};
```