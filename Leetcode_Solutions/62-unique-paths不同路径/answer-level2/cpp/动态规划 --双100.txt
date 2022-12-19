```
class Solution {
public:
    int uniquePaths(int m, int n) {
        //输入的行列数不是正数时
        if(m <= 0 || n <= 0)
            return 0;
        //至少有一个元素
        int dp[m][n];
        for(int i = m-1;i >= 0;i--)
        {
            for(int j = n-1;j >= 0;j--)
            {
                //最后一行和最后一列的值都为1
                if(i == m-1 || j == n-1)
                    dp[i][j] = 1;
                //其余元素
                else
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
```
