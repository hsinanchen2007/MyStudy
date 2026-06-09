时间：87.89%
空间：100.00%
具体递推式为：dp[i][j] += min(dp[i-1][j], dp[i][j-1]);//从上或从左来
其余思路注释里呈现：
```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(); //获取行数
        int m = grid[0].size(); //获取列数
        
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                //注意，对于第0行/列的数值，需要进行特判处理
                if(i == 0 && j != 0) //第0行 
                    grid[i][j] += grid[i][j-1];
                else if(j == 0 && i != 0) //第0列
                    grid[i][j] += grid[i-1][j];
                else if(i != 0 && j != 0) //其余（不需要特判）
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);//递推式（原地修改）
            }
        }
        return grid[n-1][m-1];
    }
};
```
