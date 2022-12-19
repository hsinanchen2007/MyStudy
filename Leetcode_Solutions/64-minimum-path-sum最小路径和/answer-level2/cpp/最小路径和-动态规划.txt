比较常规的动态规划。
定义m为输入数组的行数，n为输入数组的列；
状态dp[i][j]表示第i行，第j列的最小路径，那么dp[m-1][n-1]就是最终结果。
状态转移方程：
dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j],即表示从上一个最小的位置，移动到i行j列。

初始化：第一行的所有元素和第一列的所有元素只有有唯一的路径，要么一直向右，要么一直向下，所以直接路径相加即可初始化。
下面呈上代码：
```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            dp[i][0] = (i == 0 ? 0 : dp[i - 1][0]) + grid[i][0]; // 计算第一列的结果
        }
        for(int i = 0; i < n; i++){
            dp[0][i] = (i == 0 ? 0 : dp[0][i - 1] )  + grid[0][i]; // 计算第一行的结果
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]; // 状态转移方程
            }
        }
        return dp[m - 1][n - 1];
    }
};
```

一般动态规划的空间都可优化，这里示范下
因为计算某一行的时候，依赖的是左一结果和上一结果，所以我们存一行的记录，只要这一行包含当前元素的左一结果和上一结果即可。
所以在dp[n]这个数组里面，dp[0]...dp[j-1]是本一行的，dp[j]...dp[n]是上一行。写的不好，大家看代码理解下吧。

```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            dp[i] = (i == 0 ? 0 : dp[i - 1]) + grid[0][i];  // 初始化第一行
        }
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j == 0){
                    dp[j] = dp[j] + grid[i][j];
                }else{
                   dp[j] = min(dp[j-1], dp[j]) + grid[i][j]; // 左边和上边，哪一个小就从哪里走过来。
                }
            }
        }
        return dp[n - 1];
    }
};
```

其实空间是可以优化成O(min(m,n))的，只是把按行迭代改成按列迭代，dp的数组代表是列结果。

