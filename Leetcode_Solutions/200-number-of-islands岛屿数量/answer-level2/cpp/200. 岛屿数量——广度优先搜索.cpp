### 解题思路

使用广度优先搜索BFS来遍历所有的节点，利用数组visited来记录每个节点是否被访问过。在遍历每个值为'1'的节点时，将该节点标记为true，同时遍历该节点的上下左右四个节点。

在主函数中对每个值为'1'且没有被遍历过的节点应用bfs，每次对结果加1，就能得到岛屿数量。

### 代码

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int res = 0;
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(i, j, grid, visited);
                    res++;
                }
            }
        }
        return res;
    }
private:
    int m, n;
    void bfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0' || visited[x][y]) {
            return;
        }
        visited[x][y] = true;
        bfs(x-1, y, grid, visited);
        bfs(x+1, y, grid, visited);
        bfs(x, y-1, grid, visited);
        bfs(x, y+1, grid, visited);
    }
};
```