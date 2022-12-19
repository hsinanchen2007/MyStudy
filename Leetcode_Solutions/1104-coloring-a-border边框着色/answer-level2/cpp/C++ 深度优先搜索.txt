### 解题思路
深度优先遍历染色
1，利用负数表示数据已经遍历过，并可以改变符号复原
2，判断一个色点是否处于边缘，若是则染色

### 代码

```cpp
class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool valid(int r, int c, int R, int C) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }
    void dfs(vector<vector<int> >& grid, int r, int c, int R, int C, int color, vector<vector<int> >& res) {
        res[r][c] *= -1;
        bool is_edge = false;
        for (int k = 0; k < 4; ++k) {
            int nr = r + dirs[k][0];
            int nc = c + dirs[k][1];
            if (!valid(nr, nc, R, C) || grid[nr][nc] != grid[r][c]) {
                is_edge = true;
            }
            if (valid(nr, nc, R, C) && res[nr][nc] == grid[r][c]) {
                dfs(grid, nr, nc, R, C, color, res);
            }
        }
        res[r][c] *= -1;
        if (is_edge) {
            res[r][c] = color;
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<int> > res = grid;
        dfs(grid, r0, c0, R, C, color, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/3254156a2f93a7623cb994583dc6952b73bccd3119082992aa223ca45f9d35ed-image.png)
