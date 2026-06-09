### 解题思路
二维动态规划，dp[i][j]表示m=i,n=j,不同路径个数，因为ij位置只能来自于i-1,j或者i,j-1,所以转移方程dp[i][j]=dp[i-1][j]+dp[i][j-1]

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        for(int i=0;i<=n;i++)dp[1][i] = 1;
        for(int i=0;i<=m;i++)dp[i][1] = 1;
        for(int i=2;i<=m;i++){
            for(int j=2;j<=n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};
```