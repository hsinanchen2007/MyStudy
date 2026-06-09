### 解题思路
1.DFS

### 代码

```cpp
class Solution {
    int n, m;
    vector<vector<bool>> vis;
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    bool isInArea(int x, int y) {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    void dfs(vector<vector<char>>& grid, int x, int y) {
        vis[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (isInArea(nx, ny) && grid[nx][ny] == '1' && !vis[nx][ny]) {
                dfs(grid, nx, ny);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) {
            return 0;
        }
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        vis = vector<vector<bool>>(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;

    }
};
```

2.并查集
```
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    count++;
                } else {
                    parent.push_back(-1);
                }
            }
        }
    }
    int find(int i) {
        while(i != parent[i]) {
            i = parent[i];
        }
        return i;
    }
    void Union(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) {
            return;
        }
        parent[rootx] = rooty;
        count--;
    }
    int getCount() {
        return count;
    }
private:
    int count;
    vector<int> parent;
};
class Solution {
    
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) {
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        UnionFind uf(grid);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    if (i - 1 >= 0 && grid[i-1][j] == '1') 
                        uf.Union(i * m + j, (i-1) * m + j);
                    if (i + 1 < n && grid[i+1][j] == '1') 
                        uf.Union(i * m + j, (i+1) * m + j);
                    if (j - 1 >= 0 && grid[i][j-1] == '1') 
                        uf.Union(i * m + j, i * m + j - 1);
                    if (j + 1 < m && grid[i][j+1] == '1') 
                        uf.Union(i * m + j, i * m + j + 1);
                }
            }
        }
        return uf.getCount();

    }
};
```
