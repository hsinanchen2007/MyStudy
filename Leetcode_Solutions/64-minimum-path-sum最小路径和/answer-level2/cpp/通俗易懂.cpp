典型的动态规划题。
首先根据题意，该网格由一个二维数组m×n构成，因此可以得到路径开始于左上角也就是二维数组的 **[0][0]** 位置，通过向右或者向下移动最终到达终点为 **[m][n]** 的点，现在要使得该路径的和最小，就要使用动态规划法。

根据动态规划的一般步骤：

 - 分析问题和求得子问题； 我们将求得最终的最短路径定为最终问题，求得阶段的最短路径为子问题
 - 边界条件；当遍历到二维数组的右边界和下边界，该求解过程结束
 - 状态转移方程；从左上角开始到右下角
 **dp[i][j] += min(dp[i-1][j], dp[i][j-1]) + grid[i][j];**
 - 求解

不过当我们使用dp数组来存储最短路径结果时会发现，当i = 0, j = 0，时会存在边界问题。观察可知第一行只能向**右**前进，第一列只能向**下**前进， 因此我们将第一行和第一列提前算出结果，此时就不用考虑边界情况。

当循环结束时，返回**dp[m][n]** ， 就是最短路径。

```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int row = grid.size();      
        int column = grid.back().size();
        vector<vector<int>> dp(row, vector<int>(column, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < row; i++){       //  Caculate result of the first column
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int j = 1; j < column; j++){    //  Caculate result of the first row
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for(int i = 1; i < row; i++){
            for(int j = 1; j < column; j++){
                //  state transition equation
                dp[i][j] += min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[row-1][column-1];
    }
};
```
