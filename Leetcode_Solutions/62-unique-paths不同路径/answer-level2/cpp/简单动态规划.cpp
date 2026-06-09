与题目14 礼物最大值类似
状态转移方程为：dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
可以优化为一维的动态数组
代码如下：
二维的dp
```
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                int a = 0,b = 0;
                if(i > 0){
                    a = dp[i - 1][j];
                }
                if(j > 0){
                    b = dp[i][j - 1];
                }
                if(i == 0 && j == 0){
                    dp[0][0] = 1;
                }
                else{
                    dp[i][j] = a + b;
                }
               
            }
        }
        return dp[m - 1][n - 1];
    }
};
```
优化后的一维dp：
```
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n);
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                int a = 0,b = 0;
                if(i > 0){
                    a = dp[j];
                }
                if(j > 0){
                    b = dp[j - 1];
                }
                if(i == 0 && j == 0){
                    dp[0] = 1;
                }
                else{
                    dp[j] = a + b;
                }
            }
        }
        return dp[n - 1];
    }
};
```
