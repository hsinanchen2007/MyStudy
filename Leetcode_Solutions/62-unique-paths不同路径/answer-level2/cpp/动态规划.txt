### 解题思路
假设dp[i][j]表示i x j网格的路径数
状态转移方程为dp[i][j]=dp[i][j-1]+dp[i-1][j]，即当前位置的值等于其左边和上边两个位置的值之和
因为只能向下和向右移动，所以说第一列和第一排的值都只能为1，即dp[0][j]=dp[i][0]=1

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++)
        {
            dp[0][i]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

};
```