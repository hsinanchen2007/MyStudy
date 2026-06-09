### 解题思路
![1.png](https://pic.leetcode-cn.com/7fa2a39b272b54263aa8b20c51353bfd4a325bddf9538f52d8aec4c372afa33b-1.png)
题解链接：https://leetcode-cn.com/problems/matrix-block-sum/solution/biweeklycontest17-q2-ju-zhen-qu-yu-he-by-happy_yux/

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(); int n = mat[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++)
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
        }

        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = max(0, i - K), y1 = max(0, j - K);
                int x2 = min(m - 1, i + K), y2 = min(n - 1, j + K);
                res[i][j] = dp[x2 + 1][y2 + 1] - dp[x1][y2 + 1] - dp[x2 + 1][y1] + dp[x1][y1];
            }
        }
        return res;
    }
};
```