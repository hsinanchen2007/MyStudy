# 问题分解

终点设置为(m-1, n-1)， 欲求从(0, 0) 到(m-1, n-1)的路径总数。 
其中，有个规律不难找到：
通过任意一点(i, j)到达终点的路径数 = 通过(i, j+1)到达终点数 + 通过(i+1, j)到达终点数
这样的思路从(0, 0)开始不好求，那就从(m-1, n-1)开始求呗。
...
上代码
```
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        int dp[m][n] ;
        for(int i=0; i<m;i++)
            for(int j=0; j<n; j++)
                dp[i][j] = 0;
        dp[m-1][n-1] = 1;  // 终点到终点路径数为1
        for(int i=m-1; i>=0; i--)
            for(int j=n-1; j>=0; j--)
            {
                // 对于任意一点(i, j) 的上一步可能是(i, j-1)，
                // 但是(i, j-1) 的下一步不一定只有(i, j), 顾这里需要使用 += 。
                if((j - 1) >= 0) dp[i][j-1] += dp[i][j]; 
                if((i - 1) >= 0) dp[i-1][j] += dp[i][j]; // 同理。
            }
        return dp[0][0]; // 这样我们从后往前获取了所有路径， 返回dp(0, 0)即可。
    }
};
```
$time cost: O(mn)$
$space cost: O(mn)$