### 解题思路
动态规划，最直观最好想的方法

### 代码

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[0][i] = A[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int lastRowMin = 0;
                if (j == n - 1) {
                    lastRowMin = min(dp[i - 1][j], dp[i - 1][j - 1]);
                } else if (j == 0) {
                    lastRowMin = min(dp[i - 1][j], dp[i - 1][j + 1]);
                } else {
                    lastRowMin = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i - 1][j + 1]);
                }
                dp[i][j] = A[i][j] + lastRowMin;
            }
        }

        int minVal = INT_MAX;
        for (int i = 0; i < n; i++) {
            minVal = min(minVal, dp[n - 1][i]);
        }

        return minVal;
    }
};
```