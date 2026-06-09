## 思路
图深度优先搜索。
## 代码
```c++
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    int tmp = getArea(i, j, grid);
                    res = max(res, tmp);
                }
            }
        }
        return res;
    }
    int getArea(int row, int col, vector<vector<int>> &grid) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) {
            return 0;
        }
        int res = 1;
        grid[row][col] = 0;// 访问过设置为0
        res += getArea(row, col - 1, grid);
        res += getArea(row, col + 1, grid);
        res += getArea(row + 1, col, grid);
        res += getArea(row - 1, col, grid);                       
        return res;
    }
};
```
