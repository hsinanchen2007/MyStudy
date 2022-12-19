### 解题思路
定义dp[][]，表示当此点的字符为1时，以该点为右下角的最大正方形边长。
初始化dp[0][\*]和dp[\*][0]，为matrix对应的字符值，状态转移方程为：
dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
最大的dp[][]即为最大正方形的边长。
一定注意matrix中保存的是字符，而不是数值。

### 代码

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        
        vector<vector<int>> dp(matrix.size());
        for (auto& i : dp)
        // for (int i = 0; i < matrix.size(); i++)
            i.resize(matrix[0].size());
        int result = 0;

        for (int i = 0; i < matrix[0].size(); i++) {
            dp[0][i] = matrix[0][i] - '0';
        }
        for (int i = 0; i < matrix.size(); i++) {
            dp[i][0] = matrix[i][0] - '0';
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
                    dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                    dp[i][j] += 1;
                    if (dp[i][j] > result)
                        result = dp[i][j];
                } else
                    dp[i][j] = 0;
            }
        }

        if (result == 0) {
            for (int i = 0; i < matrix[0].size(); i++) {
                if (matrix[0][i] == '1') {
                    result = 1;
                    break;
                }
            }
        }
        if (result == 0) {
            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i][0] == '1') {
                    result = 1;
                    break;
                }
            }
        }

        return result * result;
    }
};
```