DFS
```
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size()==0) return 0;
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') { //扫描到一个为1的点作为根节点做深度搜索直到紧连的没有为1的点
                    ++res; //已经扫描过的点会被标记，即值为0，所以最终根节点数为岛屿数
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0'; //标记已经扫描过的
        if (i >= 1 && grid[i-1][j] == '1') dfs(grid, i - 1, j); //以某点为中心向上扫描,注意边界
        if (i < grid.size()-1 && grid[i+1][j] == '1') dfs(grid, i + 1, j); //以某点为中心向下扫描
        if (j >= 1 && grid[i][j-1] == '1') dfs(grid, i, j - 1); //以某点为中心向左扫描
        if (j < grid[0].size()-1 && grid[i][j+1] == '1') dfs(grid, i, j + 1); //以某点为中心向右扫描
    }
};
```
BFS
```
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size()==0) return 0;
        queue<pair<int, int>> que;
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0'; 
                    ++res;
                    que.push({i, j});
                    while (!que.empty()) {
                        auto q = que.front();
                        que.pop();
                        int r = q.first, c = q.second;
                        if (r >= 1 && grid[r-1][c] == '1') {
                            que.push({r-1, c});
                            grid[r-1][c] = '0';
                        }
                        if (r < grid.size()-1 && grid[r+1][c] == '1') {
                            que.push({r+1, c}); 
                            grid[r+1][c] = '0';
                        }
                        if (c >= 1 && grid[r][c-1] == '1') {
                            que.push({r, c-1}); 
                            grid[r][c-1] = '0';
                        }
                        if (c < grid[0].size()-1 && grid[r][c+1] == '1') {
                            que.push({r, c+1}); 
                            grid[r][c+1] = '0';
                        }
                    }
                }
            }
        }
        return res;
    }
};
```
