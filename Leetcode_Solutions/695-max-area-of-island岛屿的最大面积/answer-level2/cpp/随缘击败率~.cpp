### 解题思路
这道题BFS，DFS都试过了，跑的很随缘。一样的代码有时候能击败99%，有时候击败29%。反正BFS/DFS都写了，是个比较简单的练习题。

### 代码
DFS:
```cpp
class Solution {
private:
    int _dfs(vector<vector<int>>& grid, int y, int x) {
        if (y < 0 || x < 0 || y == grid.size() || x == grid[y].size() || !grid[y][x]) {
            return 0;
        }
        grid[y][x] = 0;
        return _dfs(grid, y, x+1) + _dfs(grid, y, x-1) + _dfs(grid, y-1, x) + _dfs(grid, y+1, x) + 1;
    }


public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j]) {
                    maxSize = max(_dfs(grid, i, j), maxSize);
                }
            }
        }
        return maxSize;
    }
};
```
BFS:
```cpp
//执行用时 :16 ms, 在所有 C++ 提交中击败了81.43% 的用户
//内存消耗 :24.7 MB, 在所有 C++ 提交中击败了5.71%的用户

class Solution {
private:
    int _rows, _cols;
    bool _visited[50][50];

private:
    bool _is_legal(vector<vector<int>>& grid, int y, int x) {
        return y >= 0 && y < _rows && x >= 0 && x < _cols && grid[y][x] && !_visited[y][x];
    }

    void _update(queue<pair<int, int>>& q, int y, int x, int &cnt) {
        q.push({ y, x });
        _visited[y][x] = true;
        cnt += 1;
    }

public:

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // init
        _rows = grid.size(), _cols = grid[0].size();
        int maxSize = 0;

        memset(_visited, false, 50*50);
        queue<pair<int, int>> q;
        
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _cols; ++j) {
                if (_is_legal(grid, i, j)) {
                    int cnt = 0;
                    _update(q, i, j, cnt);
                    while (!q.empty()) {
                        int y = q.front().first, x = q.front().second;
                        q.pop();
                        if (_is_legal(grid, y, x+1)) { _update(q, y, x+1, cnt); }
                        if (_is_legal(grid, y, x-1)) { _update(q, y, x-1, cnt); }
                        if (_is_legal(grid, y-1, x)) { _update(q, y-1, x, cnt); }
                        if (_is_legal(grid, y+1, x)) { _update(q, y+1, x, cnt); }
                    }
                    if (cnt > maxSize) {
                        maxSize = cnt;
                    }
                }
            }
        }
        return maxSize;
    }
};
```