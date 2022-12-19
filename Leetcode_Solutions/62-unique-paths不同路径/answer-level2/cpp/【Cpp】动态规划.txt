### 解题思路

动态规划三部曲:

a. 定义子问题
b. 状态数组
c. 转移方程

子问题: 到i,j的路径数 = 到i-1,j的路径数 + 到i,j-1的路径数

状态数组: f[i][j] 

转移方程: dp[i][j] = dp[i-1][j] + dp[i][j-1];

### 代码

注释初始化，第一行和第一列为1，类似于斐波那契数列数列中初始化n=0,n=1的情况。

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;

        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

```