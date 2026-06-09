# 62.不同路径

关注填表方向，这里使用的是一个二维表来存储走过的路径数。
填表方向可以有三种，一是逐列，二是逐行，还有一种是沿着左下-右上对角线方向。这里采用的是逐行的方式。

base case是dp[0][0]处，只有一条路径能到达。
+ 对于第一行的其他位置，路径数的状态方程为：
$$dp[i][j] = dp[i][j-1]$$
+ 对于第一列中的其他位置，路径数的状态方程为：
$$dp[i][j] = dp[i-1][j]$$
+ 对于其他位置，路径数的状态方程为：
$$dp[i][j] = dp[i-1][j] + dp[i][j-1]$$


```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0) {
                    if(j==0) dp[i][j]=1;
                    else dp[i][j]=dp[i][j-1];
                }else{
                    if(j==0) dp[i][j]=dp[i-1][j];
                    else dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
```
