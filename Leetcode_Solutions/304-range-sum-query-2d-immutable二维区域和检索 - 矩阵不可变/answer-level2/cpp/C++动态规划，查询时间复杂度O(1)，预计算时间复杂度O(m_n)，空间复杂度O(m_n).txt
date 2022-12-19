
我们用一个数组dp[m][n]来存储所有左上角位于(0, 0)的子矩阵的元素和。

这样，对任意的子矩阵，设其左上角为(row1, col1)，右下角为(row2, col2)，则它的元素和就等于：

dp[row2][col2] - dp[row2][col1-1] - dp[row1-1][col2] + dp[row1-1][col1-1]

这样就可以实现常数时间的查询。接下来的关键是求解dp[m][n]。

当i = 0时，有dp[0][j] = matrix[0][0] + ... + matrix[0][j] (0 <= j < n)；
当i > 0时，有dp[i][j] = matrix[i][0] + ... + matrix[i][j] + dp[i-1][j] (0 <= j < n)。

由此可见，关键在于求出每一行的元素和sum[i][j] = matrix[i][0] + ... + matrix[i][j]。它的求解时间为O(mn)。
求出它之后，接下来求出dp数组的时间也为O(mn)。
故总的预计算时间复杂度为O(mn)。

C++代码如下：
（注意到sum和dp可以用同一个数组来存储，从而节省空间）

```
class NumMatrix {
public:
    int m = 0, n = 0;
    int ** dp;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        if (m != 0){
            n = matrix[0].size();
            if (n != 0){
                dp = new int*[m];
                // 计算每一行的元素和sum[i][j]
                for (int i = 0; i < m;i ++){
                    dp[i] = new int[n];
                    dp[i][0] = matrix[i][0];
                    for (int j = 1;j < n;j ++)
                        dp[i][j] = dp[i][j-1] + matrix[i][j];
                }
                // 计算所有顶左上角的子矩阵的元素和dp[i][j]
                for (int i = 1;i < m;i ++)
                    for (int j = 0;j < n;j ++)
                        dp[i][j] = dp[i-1][j] + dp[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (m == 0 || n == 0)
            return 0;
        if (row1 == 0 && col1 == 0)
            return dp[row2][col2];
        else if (row1 == 0)
            return dp[row2][col2] - dp[row2][col1-1];
        else if (col1 == 0)
            return dp[row2][col2] - dp[row1-1][col2];
        else
            return dp[row2][col2] - dp[row2][col1-1] - dp[row1-1][col2] + dp[row1-1][col1-1];
    }
};
```
