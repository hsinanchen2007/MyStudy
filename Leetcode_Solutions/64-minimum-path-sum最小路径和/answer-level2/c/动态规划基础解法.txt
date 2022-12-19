```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) { // 判断空输入
            return 0;
        }
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> minPath(row, vector<int> (col, 0));
        minPath[0][0] = grid[0][0];
        for (int i = 1; i < row; i++) { // 第一列初始化
            minPath[i][0] = minPath[i-1][0] + grid[i][0];
        }
        for (int i = 1; i < col; i++) { // 第一行初始化
            minPath[0][i] = minPath[0][i-1] + grid[0][i];
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) { // 动态规划保留最小的路径和
                minPath[i][j] = min(minPath[i-1][j] + grid[i][j], minPath[i][j-1] + grid[i][j]);
            }
        }
        return minPath[row-1][col-1];
    }
};
```
