### 解题思路
状态表达式和转移方程很好写，子问题模型区别于回文字符串。

### 代码

```cpp
class Solution {
public:
    //dp[m][n] = dp[m-1][n] + dp[m][n-1]
    int uniquePaths(int m, int n) {
        int dp[m][n] = {0};
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        for(int j = 1; j < n; j++){
            for(int i = 0; i < m; i++){
                dp[i][j] = (i-1 >= 0 ? dp[i-1][j] + dp[i][j-1] : dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};
```