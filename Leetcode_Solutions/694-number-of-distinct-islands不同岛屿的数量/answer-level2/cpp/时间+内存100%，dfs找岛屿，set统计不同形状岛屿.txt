```cpp
class Solution {
public:
    int row, col;
    int numDistinctIslands(vector<vector<int>>& grid) {
        // dfs找岛屿，set统计不同形状岛屿
        // 用vector<int> 存储岛屿，存储的值为i*col+j, (i,j)为陆地在grid中的相对自身原点的坐标
        // 因为所有节点遍历的方式一样，因此若形状相同，则遍历时存储坐标的顺序也相同
        // 为减少遍历时间，维护一个vector<vector<bool>> visited, 记录该网格是否被访问过
        row = grid.size();
        col = grid[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        set<vector<int>> islands;
        for (int i = 0; i<row; i++) {
            for (int j = 0; j < col; j++) {
                vector<int> island;
                dfs(island, visited, grid, i, j, i, j);
                if (!island.empty()) islands.insert(island);
            }
        }
        return islands.size();
    }
    
    void dfs(vector<int> & island, vector<vector<bool>> &visited, vector<vector<int>>& grid, int sr, int sc, int r, int c) {
        if (r>=row || r <0 || c>=col || c<0 || visited[r][c] || !grid[r][c]) return;
        visited[r][c] = true;
        island.push_back((r-sr)*col+(c-sc));
        dfs(island, visited, grid, sr, sc, r-1, c);
        dfs(island, visited, grid, sr, sc, r+1, c);
        dfs(island, visited, grid, sr, sc, r, c-1);
        dfs(island, visited, grid, sr, sc, r, c+1);
    }
};
```
后面想了想，没有必要维护一个vector<vector<bool>> visited，直接将每次访问过的陆地置为0即可
注：以上操作不会造成漏掉陆地的情况吗？不会。因为“星星之火，可以燎原”，只要是连通的陆地，一定可以被遍历到

改进后，
![image.png](https://pic.leetcode-cn.com/dbbfdd5dc80e3e24a9ac826a5493128f621daaea4c15beb1a2731889473df2ec-image.png)

```cpp
class Solution {
public:
    int row, col;
    int numDistinctIslands(vector<vector<int>>& grid) {
        // dfs找岛屿，set统计不同形状岛屿
        // 用vector<int> 存储岛屿，存储的值为i*col+j, (i,j)为陆地在grid中的相对自身原点的坐标
        // 因为所有节点遍历的方式一样，因此若形状相同，则遍历时存储坐标的顺序也相同
        // 为减少遍历时间，将每次访问过的陆地置为0,
        // 注：以上操作不会造成漏掉陆地的情况吗？不会。因为“星星之火，可以燎原”
        row = grid.size();
        col = grid[0].size();
        set<vector<int>> islands;
        for (int i = 0; i<row; i++) {
            for (int j = 0; j < col; j++) {
                vector<int> island;
                dfs(island, grid, i, j, i, j);
                if (!island.empty()) islands.insert(island);
            }
        }
        return islands.size();
    }
    
    void dfs(vector<int> & island, vector<vector<int>>& grid, int sr, int sc, int r, int c) {
        if (r>=row || r <0 || c>=col || c<0 || !grid[r][c]) return;
        grid[r][c] = 0;
        island.push_back((r-sr)*col+(c-sc));
        dfs(island, grid, sr, sc, r-1, c);
        dfs(island, grid, sr, sc, r+1, c);
        dfs(island, grid, sr, sc, r, c-1);
        dfs(island, grid, sr, sc, r, c+1);
    }
};
```

