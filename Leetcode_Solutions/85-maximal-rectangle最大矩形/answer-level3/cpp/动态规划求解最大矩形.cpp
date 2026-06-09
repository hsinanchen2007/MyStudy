### 解题思路
动态规划
![捕获.JPG](https://pic.leetcode-cn.com/f3b2c3a16914821dbe60e7b93a46cde1065ac86a59c2a5d906d601ec71a23910-%E6%8D%95%E8%8E%B7.JPG)

### 代码

```cpp
class Solution {
public:
    // dp(i, j, 3)为三元组（向左走连续1的个数，向上走连续1的个数，包围的最大面积）
    int maximalRectangle(vector<vector<char>>& matrix) {
        int result = 0;
        if (matrix.empty()) {return result;}
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, {0, 0, 0}));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 && j == 0) {  // 左上角的值
                        dp[i][j] = {1, 1, 1};
                    } else if (i == 0) {  // 第一行
                        dp[i][j] = {dp[i][j - 1][0] + 1, 1, dp[i][j - 1][2] + 1};
                    } else if (j == 0) {  // 第一列
                        dp[i][j] = {1, dp[i - 1][j][1] + 1, dp[i - 1][j][2] + 1};
                    } else {
                        dp[i][j][0] = dp[i][j - 1][0] + 1;  // 向左连续1的个数
                        dp[i][j][1] = dp[i - 1][j][1] + 1;  // 向上连续1的个数
                        // 计算面积
                        int col_min = dp[i][j][0];  // 当前位置向左1的个数
                        int row = dp[i][j][1];  // 当前位置向上1的个数
                        for (int k = 0; k < row; k++) {
                            col_min = min(col_min, dp[i - k][j][0]);  // 向左最小的1个数
                            dp[i][j][2] = max(dp[i][j][2], col_min * (k + 1));
                        }
                    }
                    result = max(result, dp[i][j][2]);
                }
            }
        }
        return result;
    }
};
```