
```
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();//获取grid的行数
        int n = grid[0].size();//获取grid的列数
        int dp[m][n];//最基本的用二位数组做法
        memset(dp, 0, sizeof(dp));//将整个数组初始值置0
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                //第一个位置只能拿，所以直接赋值
                if(i == 0 && j == 0) {dp[i][j] = grid[i][j]; continue;}
                //如果是第一行，那只能是从左边一个过来，所以直接加
                else if(i == 0) dp[i][j] = grid[i][j] + dp[i][j - 1];
                //如果是第一列，那只能是从左边一个过来，所以直接加
                else if(j == 0) dp[i][j] = grid[i][j] + dp[i - 1][j];
                else{ //其它行列就有两种选择，从上面下来，从左边过来，选最大的
                    int x = grid[i][j] + dp[i][j - 1];
                    int y = grid[i][j] + dp[i - 1][j];
                    dp[i][j] = max(x, y);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
```
