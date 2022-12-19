# 思路
1. 将图中为代表陆地的点更改为0，代表海洋的点更改为INT_MAX
2. 从左上角开始DP
3. 从右下角开始DP(同时记录最大值)
4. 返回结果(如果最大值是0或者max代表全图都是海洋or全图是陆地, 可以在步骤1里面优化掉)

# 代码
```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();
        // Step 1
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!grid[i][j])
                    grid[i][j] = INT_MAX;
                else
                    grid[i][j] = 0;
            }
        }
        // Step 2
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    if (i > 0 && grid[i - 1][j] < grid[i][j] - 1)
                        grid[i][j] = grid[i - 1][j] + 1;
                    if (j > 0 && grid[i][j - 1] < grid[i][j] - 1)
                        grid[i][j] = grid[i][j - 1] + 1;
                }
            }
        }
        // Step 3
        int max = 0;
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (grid[i][j]) {
                    if (i < rows - 1 && grid[i + 1][j] < grid[i][j] - 1)
                        grid[i][j] = grid[i + 1][j] + 1;
                    if (j < cols - 1 && grid[i][j + 1] < grid[i][j] - 1)
                        grid[i][j] = grid[i][j + 1] + 1;
                }
                if (grid[i][j] > max)
                    max = grid[i][j];
            }
        }
        // Step 4
        return (max != INT_MAX && max != 0) ? max : -1;
    }
};
```
