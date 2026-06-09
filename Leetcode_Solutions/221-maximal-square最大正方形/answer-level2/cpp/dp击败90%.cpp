### 解题思路
当前位置所能取到的边长来源于上，左，左上三个位置的最小值，之后求面积取最大即可。

### 代码

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        if(matrix.size() == 1)
        {
            for(int i = 0 ; i < matrix[0].size() ; ++i)
                if(matrix[0][i] == '1')
                    return 1;
            return 0;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m] = {0};
        int cnt = 0, maxx = 0;
        for(int i = 0 ; i < n ; ++i)
        {
            dp[i][0] = matrix[i][0] - '0';
            if(dp[i][0] == 1)
                maxx = 1;
        }
        for(int i = 0 ; i < m ; ++i)
        {
            dp[0][i] = matrix[0][i] - '0';
            if(dp[0][i] == 1)
                maxx = 1;
        }
        for(int i = 1 ; i < n ; ++i)
        {
            for(int j = 1 ; j < m ; ++j)
            {
                if(matrix[i - 1][j] == '1' && matrix[i][j - 1] == '1' && matrix[i - 1][j - 1] == '1' && matrix[i][j] == '1')
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                else
                {
                    if(matrix[i][j] == '1')
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                maxx = max(maxx, dp[i][j] * dp[i][j]);
            }
        }
        return maxx;
    }
};
```