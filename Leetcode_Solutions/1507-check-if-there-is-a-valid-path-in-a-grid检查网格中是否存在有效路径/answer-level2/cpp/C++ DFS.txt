### 解题思路
共6种街型，每种街型有2个方向可以走，每个方向有3种街型可以对接。

![图片.png](https://pic.leetcode-cn.com/3e42520c66ac0e6baae1c69903a9a3d2b16339ca269f90ee16e121558604b41b-%E5%9B%BE%E7%89%87.png)

### 代码

```cpp
class Solution {
public:
    void WalkNext(const vector<vector<int>>& grid, stack<pair<int, int>>& stk, 
                  vector<vector<bool>>& visited, int i, int j, int dir) {
        int m = grid.size();
        int n = grid[0].size();

        if (dir == 0) { // right
            int nj = j + 1;
            if (nj < n && (grid[i][nj] == 1 || grid[i][nj] == 3 || grid[i][nj] == 5) && !visited[i][nj]) {
                stk.emplace(i, nj);
                visited[i][nj] = true;
            }
        } else if (dir == 1) { // down
            int ni = i + 1;
            if (ni < m && (grid[ni][j] == 2 || grid[ni][j] == 5 || grid[ni][j] == 6) && !visited[ni][j]) {
                stk.emplace(ni, j);
                visited[ni][j] = true;
            }
        } else if (dir == 2) { // left
            int nj = j - 1;
            if (nj >= 0 && (grid[i][nj] == 1 || grid[i][nj] == 4 || grid[i][nj] == 6) && !visited[i][nj]) {
                stk.emplace(i, nj);
                visited[i][nj] = true;
            }
        } else { // up
            int ni = i - 1;
            if (ni >= 0 && (grid[ni][j] == 2 || grid[ni][j] == 3 || grid[ni][j] == 4) && !visited[ni][j]) {
                stk.emplace(ni, j);
                visited[ni][j] = true;
            }
        }
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        stack<pair<int, int>> stk;
        stk.emplace(0, 0);
        while (!stk.empty()) {
            auto [i, j] = stk.top();
            if (i == m - 1 && j == n - 1) {
                return true;
            }
            stk.pop();
            switch (grid[i][j]) {
                case 1:
                    WalkNext(grid, stk, visited, i, j, 0);  // walk right
                    WalkNext(grid, stk, visited, i, j, 2);  // walk left
                    break;
                case 2:
                    WalkNext(grid, stk, visited, i, j, 1);  // walk down
                    WalkNext(grid, stk, visited, i, j, 3);  // walk up
                    break;
                case 3:
                    WalkNext(grid, stk, visited, i, j, 1);  // walk down
                    WalkNext(grid, stk, visited, i, j, 2);  // walk left
                    break;
                case 4:
                    WalkNext(grid, stk, visited, i, j, 0);  // walk right
                    WalkNext(grid, stk, visited, i, j, 1);  // walk down
                    break;
                case 5:
                    WalkNext(grid, stk, visited, i, j, 2);  // walk left
                    WalkNext(grid, stk, visited, i, j, 3);  // walk up
                    break;
                case 6:
                    WalkNext(grid, stk, visited, i, j, 0);  // walk right
                    WalkNext(grid, stk, visited, i, j, 3);  // walk up
                    break;
                default:
                    break;
            }
        }
        return false;
    }
};
```