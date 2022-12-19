### 解题思路
注意一下 0 0 是 1就好了，其他问题不大，比较简单的dp

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
      if(m == 0 || n == 0)  return 0;

      vector<vector<int>> dp(n, vector<int>(m, 0));
      for(int i = 0; i < n; i++)
        dp[i][0] = 1;
      for(int i = 0; i < m; i++)
        dp[0][i] = 1;
      
      for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }

      return dp[n - 1][m - 1];
    }
};
```