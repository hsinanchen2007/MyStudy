### 解题思路
DP。

### 代码

```cpp
class Solution {
public:
    //dp[i][j], 表示的是到达[i,j]这个点的最小路径和
    //dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        int dp[m][n] = {0};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[0][0] = grid[0][0];
                }
                else{
                    dp[i][j] = min(i >= 1 ? dp[i-1][j] : dp[i][j-1], j >= 1 ? dp[i][j-1] : dp[i-1][j]) + grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
```

### 解题思路
评论说有用DFS/BFS求解，接下来用这种方式试试看（虽然超时，但是巩固下思想）。