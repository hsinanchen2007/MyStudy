**Solution 1: DFS**

```cpp
class Solution {
private:
    void dfs(vector<vector<char>>& grid, bool* vis, int i, int j) {
        int n = grid.size(), m = grid[0].size();
        vis[i * m + j] = true;
        static int dx[] = {-1, 1, 0, 0};
        static int dy[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k ++) {
            int new_x = i + dx[k];
            int new_y = j + dy[k];
            if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m 
                && !vis[new_x * m + new_y] && grid[new_x][new_y] == '1')
                dfs(grid, vis, new_x, new_y);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int n = grid.size(), m = grid[0].size();
        bool vis[n*m];
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == '1' && !vis[i * m + j]) {
                    dfs(grid, vis, i, j);
                    ans ++;
                }
            }
        return ans;
    }
};
```

Solution 2: Union Find + 路径压缩
```cpp
class Solution {
private:
    void init_parent(int* parent, int length) {
        for (int i = 0; i < length; i ++)
            parent[i] = i;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int n = grid.size(), m = grid[0].size();
        int parent[n*m];
        init_parent(parent, n * m);
        function<int(int)> find = [&](int x) {
            return x == parent[x] ? x : parent[x] = find(parent[x]);
        }; 
        static int dx[] = {-1, 1, 0, 0};
        static int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < n; i ++) 
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == '1') {
                    for (int k = 0; k < 4; k ++) {
                        int new_x = i + dx[k];
                        int new_y = j + dy[k];
                        if (0 <= new_x && new_x < n && 0 <= new_y && 
                            new_y < m && grid[new_x][new_y] == '1') {
                                parent[find(new_x * m + new_y)] = find(i * m + j);
                            }
                    }
                }
            }
        int ans = 0;
        for (int i = 0; i < n * m; i ++) {
            if (grid[i/m][i%m] == '1' && parent[i] == i)
                ans ++;
        }
        return ans;
    }
};
```