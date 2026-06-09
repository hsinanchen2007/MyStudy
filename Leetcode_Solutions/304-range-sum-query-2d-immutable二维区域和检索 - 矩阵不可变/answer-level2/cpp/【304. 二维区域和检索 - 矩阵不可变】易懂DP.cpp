### 思路
暴力计算超时，因此考虑预计算的方法，在构造函数中，计算每个顶点dp[i][j]值，表示与[0, 0]点之间构成的正方形内所有数字和。
在sumRegion中，如果快速计算(r1, c1)和(r2, c2)构成矩形的值，当r1和c1都大于0，通过计算dp[r2][c2] - dp[r1 - 1][c2] - dp[r2][c1 - 1] + dp[r1 - 1][c1 - 1]即可，注意判断下标范围。

### 代码

```cpp
class NumMatrix {
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (!matrix.empty()) {
            dp = matrix;
            for (int i = 1; i < matrix.size(); ++i) { //第一列
                dp[i][0] += dp[i - 1][0];
            }
            for (int j = 1; j < matrix[0].size(); ++j) { //第一行
                dp[0][j] += dp[0][j - 1];
            }
            for (int i = 1; i < matrix.size(); ++i) {
                for (int j = 1; j < matrix[i].size(); ++j) {
                    dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]; 
                }
            }
        }        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        res += dp[row2][col2];
        if (row1 > 0 && col1 > 0) {
            res += dp[row1 - 1][col1 - 1] - dp[row1 - 1][col2] - dp[row2][col1 - 1];
        } else if (row1 > 0) {
            res -= dp[row1 - 1][col2];
        } else if (col1 > 0) {
            res -= dp[row2][col1 - 1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
```