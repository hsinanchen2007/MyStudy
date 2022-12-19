### 解题思路
dp

### 代码

```cpp
class Solution {
public:
    int longestLine(vector<vector<int>>& M)
    {
        if (M.size() == 0 || M[0].size() == 0) {
            return 0;
        }

        int m = M.size();
        int n = M[0].size();

        int result = 0;
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(m, vector<int>(n, 0)));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 1) {
                    dp[0][i][j] = j > 0 ? dp[0][i][j - 1] + 1 : 1;
                    dp[1][i][j] = i > 0 ? dp[1][i - 1][j] + 1 : 1;
                    dp[2][i][j] = i > 0 && j > 0 ? dp[2][i - 1][j - 1] + 1 : 1;
                    dp[3][i][j] = i > 0 && j < n - 1 ? dp[3][i - 1][j + 1] + 1 : 1;

                    int max1 = max(dp[0][i][j], dp[1][i][j]);
                    int max2 = max(dp[2][i][j], dp[3][i][j]);
                    result = max(result , max(max1, max2));
                }
            }
        }

        return result;
    }
};
```