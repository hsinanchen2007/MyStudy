### 解题思路
    /*
     * 深度优先遍历
     *
     * 对于图、矩阵等的遍历通常采用深度优先遍历和广度优先遍历。
     * 先遍历矩阵找到值为1的点，为了避免重复查找，
     * 在遍历过该点后将该点设为0，同时对面积增加1。
     * 从该点开始对其上下左右的点进行递归遍历判断，如果为1则重复上述操作。
     * 当该点旁边的点都找完只剩下为0的点后，继续遍历矩阵找其他为1的点，
     * 同时每次更新面积为当前的最大面积值。
     * */
### 代码

```cpp
int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
    if (grid.empty()) {
        return 0;
    }

    // 只有一行或一列时，返回0
    if (grid[0].size() == 0 || grid.size() == 0) {
        return 0;
    }

    // 面积计数
    int count = 0;

    // 遍历矩阵找到为1的点
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            // 如果点为1，则对其周围的点进行判断
            if (grid[i][j] == 1) {
                // 每次更新面积计数为最大面积值
                count = std::max(count, dfs(grid, i, j));
            }
        }
    }
    return count;
}

int dfs(std::vector<std::vector<int>> &grid, int x, int y) {
    // 将遍历过的点置为0，避免重复访问
    grid[x][y] = 0;

    // 当前面积只有一个点，
    // 所以初始化为1
    int count = 1;

    // 判断当前点的左边是否为1
    if (x - 1 >= 0 && x - 1 < grid.size() && y >= 0 && y < grid[0].size() && grid[x - 1][y] == 1) {
        // 如果为1，则将面积加上该点递归遍历后的值
        count += dfs(grid, x - 1, y);
    }

    // 判断当前点的左边是否为1
    if (x + 1 >= 0 && x + 1 < grid.size() && y >= 0 && y < grid[0].size() && grid[x + 1][y] == 1) {
        // 如果为1，则将面积加上该点递归遍历后的值
        count += dfs(grid, x + 1, y);
    }

    // 判断当前点的左边是否为1
    if (x >= 0 && x < grid.size() && y - 1 >= 0 && y - 1 < grid[0].size() && grid[x][y - 1] == 1) {
        // 如果为1，则将面积加上该点递归遍历后的值
        count += dfs(grid, x, y - 1);
    }

    // 判断当前点的左边是否为1
    if (x >= 0 && x < grid.size() && y + 1 >= 0 && y + 1 < grid[0].size() && grid[x][y + 1] == 1) {
        // 如果为1，则将面积加上该点递归遍历后的值
        count += dfs(grid, x, y + 1);
    }

    return count;
}
```