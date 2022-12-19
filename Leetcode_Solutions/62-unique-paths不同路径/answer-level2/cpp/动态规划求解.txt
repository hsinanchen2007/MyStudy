### 解题思路
本题采用动态规划易于求解
（1）因为只能向下或者向右，因此                    
`dp[x][y] = dp[x + 1][y] + dp[x][y + 1];`
（2）最终点为1，边上两行均只有一种解

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int x, y;
        int dp[m][n] = {0};

        for (x = m - 1; x >= 0; x--)
        {
            for (y = n - 1; y >= 0; y--)
            {
                if ((x == m - 1 && n - y == 2) || (y == n - 1 && m - x == 2))
                    dp[x][y] = 1;
                else if (x == m - 1 && n - y > 2)
                    dp[x][y] = dp[x][y + 1];
                else if (y == n - 1 && m - x > 2)
                    dp[x][y] = dp[x + 1][y];
                else if (n - y >= 2 && m - x >= 2)
                    dp[x][y] = dp[x + 1][y] + dp[x][y + 1];
                else dp[x][y] = 1;              
            }
        }

        return dp[0][0];
    }
};
```