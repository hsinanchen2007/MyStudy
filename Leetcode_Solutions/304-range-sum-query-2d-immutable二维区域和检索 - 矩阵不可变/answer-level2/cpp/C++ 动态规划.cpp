# 构造函数
## 时间复杂度: $O(MN)$
## 空间复杂度: $O(1)$
## 状态转移公式:
$dp[i][j]$用来表示$matrix$中从$(0, 0)$到$(i, j)$之间所有的值
$dp[i - 1][j]$和$dp[i][j - 1]$的重叠区域是$dp[i - 1][j - 1]$
故而有
$dp[i][j] = matrix[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]$

# sumRegion
## 时间复杂度: O(1)
## 空间复杂度: O(1)
## 状态转移公式:
$ret = dp[row2][cols] - (dp[row1 - 1][col2] + dp[row2][col1 - 1] - dp[row1][col1])$

# 代码

```cpp
class NumMatrix {
private:
    vector<vector<int>> dp;
    int rows = 0;
    int cols = 0;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        dp = std::move(matrix);
        rows = dp.size();
        if (rows)
            cols = dp[0].size();
        else
            return;
        for (int i = 1; i < rows; i++)
            dp[i][0] += dp[i - 1][0];
        for (int j = 1; j < cols; j++)
            dp[0][j] += dp[0][j - 1];
        for (int i = 1; i < rows; i++)
            for (int j = 1; j < cols;j ++) {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        auto ret = dp[row2][col2];
        row1--;
        col1--;
        if (row1 >= 0)
            ret -= dp[row1][col2];
        if (col1 >= 0)
            ret -= dp[row2][col1];
        if (row1 >= 0 && col1 >= 0)
            ret += dp[row1][col1];
        return ret;
    }
};
```