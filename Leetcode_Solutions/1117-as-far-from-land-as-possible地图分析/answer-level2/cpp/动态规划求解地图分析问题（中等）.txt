### 解题思路
动态规划
![捕获.JPG](https://pic.leetcode-cn.com/a19025c529b499bc8f41e54c59c114a20995f02a9122d3f4fe19de48557ac5d2-%E6%8D%95%E8%8E%B7.JPG)

### 代码

```cpp
class Solution {
public:
    const int INF = int(1E6);
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = grid[i][j]? 0:INF;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {continue;}
                if (i - 1 >= 0) {dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);}
                if (j - 1 >= 0) {dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);}
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j]) {continue;}
                if (i + 1 < n) {dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);}
                if (j + 1 < n) {dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);}
            }
        }
        int result = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) {
                    result = max(result, dp[i][j]);
                }
            }
        }
        return result == INF?-1:result;
    }
};
```