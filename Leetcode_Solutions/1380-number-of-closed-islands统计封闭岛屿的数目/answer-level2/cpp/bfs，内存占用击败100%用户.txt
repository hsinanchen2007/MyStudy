### 解题思路
使用bfs算法，只有当0一直连通到边缘时，这片0的区域才不是孤岛。把所有0都搜一遍，把已经搜索过的0置为-1。
当一个0的上下左右全部都没有未搜索过的0并且这个0不在边缘，那么这个搜索分支正常结束。当所有的搜索分支都正常结束，那么这次搜索的区域成为一个孤岛。

### 代码

```cpp
class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j) {
        if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[i].size() - 1) {
            return 0;
        }
        grid[i][j] = -1;
        int result = 1;

        if (grid[i - 1][j] == 0) {
            result &= bfs(grid, i - 1, j);
        }
        if (grid[i + 1][j] == 0) {
            result &= bfs(grid, i + 1, j);
        }
        if (grid[i][j - 1] == 0) {
            result &= bfs(grid, i, j - 1);
        }
        if (grid[i][j + 1] == 0) {
            result &= bfs(grid, i, j + 1);
        }
        return result;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    int ret = bfs(grid, i, j);
                    if (ret == 1) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
```