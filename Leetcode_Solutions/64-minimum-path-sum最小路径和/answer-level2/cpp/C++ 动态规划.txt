### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //创建m*n的大小dp表
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size()));
        //base case
        if(grid.size() == 0){
            return 0;
        }
        //初始dp表中第一个数；
        dp[0][0] = grid[0][0];
        //初始化dp表中的第一行
        for(int i = 1; i< n;i++){
            dp[0][i] = dp[0][i-1]+grid[0][i];
        }
        //初始化dp表中第一列
        for(int j = 1; j < m;j++){
            dp[j][0] = dp[j-1][0]+grid[j][0];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j< n;j++){
                dp[i][j] = min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j]);
            }
        }
        return dp[m-1][n-1];
    }
};
```