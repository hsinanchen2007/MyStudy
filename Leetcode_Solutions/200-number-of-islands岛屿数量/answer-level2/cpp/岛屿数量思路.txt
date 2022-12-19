### 解题思路
其通过队列的广度搜索找到陆地最大联通的区域，每一个连通区域就是一个独立的岛

### 代码

```cpp
class Solution {
    public:
    int numIslands(vector<vector<char>>& grid) {
        // 地图的行
        int nr = grid.size();
        if (!nr) return 0;
        // 地图的列
        int nc = grid[0].size();

        // 岛的数量
        int num_islands = 0;
        // 遍历网格
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                // 如果格子是l，则认为是陆地
                if (grid[r][c] == '1') {
                    // 岛的数量+1
                    ++num_islands;
                    // 将其置为0，表示已访问过，
                    grid[r][c] = '0'; // mark as visited
                    // 定义一个队列，命名为nei***ors，奇葩的名字
                    queue<pair<int, int>> neiors;
                    // 将该格子存储在队列中
                    neiors.push({r, c});
                    // 队列不为空
                    while (!neiors.empty()) {
                        // 取出队列的第一个元素
                        auto rc = neiors.front();
                        // 出队列
                        neiors.pop();
                        // 该格子所在的行列
                        int row = rc.first, col = rc.second;
                        // 搜索上面的格子，如果是陆地则入栈，并且设置为0，不在遍历该区域
                        if (row - 1 >= 0 && grid[row-1][col] == '1') {
                            neiors.push({row-1, col}); grid[row-1][col] = '0';
                        }
                        // 搜索下面的格子，如果是陆地则入栈，并且设置为0，不在遍历该区域
                        if (row + 1 < nr && grid[row+1][col] == '1') {
                            neiors.push({row+1, col}); grid[row+1][col] = '0';
                        }
                        // 搜索左边的格子，如果是陆地则入栈，并且设置为0，不在遍历该区域
                        if (col - 1 >= 0 && grid[row][col-1] == '1') {
                            neiors.push({row, col-1}); grid[row][col-1] = '0';
                        }
                        // 搜索右边的格子，如果是陆地则入栈，并且设置为0，不在遍历该区域
                        if (col + 1 < nc && grid[row][col+1] == '1') {
                            neiors.push({row, col+1}); grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }

        return num_islands;
    }
};
```