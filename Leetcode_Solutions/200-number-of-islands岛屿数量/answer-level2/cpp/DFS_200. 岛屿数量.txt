### 解题思路
    /*
     * 深度优先遍历(DFS)
     *
     * 对于图、矩阵等的遍历通常采用深度优先遍历和广度优先遍历。
     * 先遍历二维网格，查找到等于字符1的点，为了避免重复查找，
     * 将该字符修改为字符0。从该字符1开始，对其上下左右的点进行判断，
     * 如果其上下左右的点是字符1则对它进行递归遍历，重复上述操作。
     *
     * 当递归返回后，表明这是一个岛屿，将岛屿计数加1，最终返回所以岛屿数。
     * */
### 代码

```cpp
int numIslands(std::vector<std::vector<char>> &grid) {
    if (grid.empty()) {
        return 0;
    }

    int rows = grid.size();
    int cols = grid[0].size();

    if (rows == 0 || cols == 0) {
        return 0;
    }

    // 计数岛屿数
    int count = 0;

    // 递归查找等于字符1的点
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // 如果该点为字符1，则对其上下左右的点进行判断
            if (grid[i][j] == '1') {
                dfs(grid, i, j);
                // 递归返回表明为岛屿，
                // 岛屿数加1
                count++;
            }
        }
    }


    return count;
}

void dfs(std::vector<std::vector<char>> &grid, int x, int y) {
    // 为避免重复查找，
    // 将访问过的字符1修改为字符0
    grid[x][y] = '0';

    // 判断该点左边的字符是否为字符1
    if (x - 1 >= 0 && x - 1 < grid.size() && y >= 0 && y < grid[0].size() && grid[x - 1][y] == '1') {
        // 如果为字符1，则对它递归遍历
        dfs(grid, x - 1, y);
    }

    // 判断该点右边的字符是否为字符1
    if (x + 1 >= 0 && x + 1 < grid.size() && y >= 0 && y < grid[0].size() && grid[x + 1][y] == '1') {
        // 如果为字符1，则对它递归遍历
        dfs(grid, x + 1, y);
    }

    // 判断该点上边的字符是否为字符1
    if (x >= 0 && x < grid.size() && y - 1 >= 0 && y - 1 < grid[0].size() && grid[x][y - 1] == '1') {
        // 如果为字符1，则对它递归遍历
        dfs(grid, x, y - 1);
    }

    // 判断该点下边的字符是否为字符1
    if (x >= 0 && x < grid.size() && y + 1 >= 0 && y + 1 < grid[0].size() && grid[x][y + 1] == '1') {
        // 如果为字符1，则对它递归遍历
        dfs(grid, x, y + 1);
    }
}
```