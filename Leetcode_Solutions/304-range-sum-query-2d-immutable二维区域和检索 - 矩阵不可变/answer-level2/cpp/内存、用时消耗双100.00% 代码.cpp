### 解题思路
此处撰写解题思路
动态规划思想：dp[i][j]表示从matrix[0][0]到matrix[i][j]的所有数的总和，则（row1，col1）到（row2，col2）的和为：1.row1 == row2 && col1 == col2时，sum = dp[row2][col2] - dp[row2 - 1][col2] - dp[row2][col2 - 1] + dp[row2 - 1][col2 - 1];2.否则，sum = dp[row2][col2] - dp[row1 - 1][col2] - dp[row2][col1 - 1] + dp[row1 - 1][col1 - 1];
以上是一般情况，再依据上述思路，分别讨论0 == row1和0 == col1的情况即可

### 代码

```cpp
    class NumMatrix {
    public:
        NumMatrix(vector<vector<int>>& matrix) {
            if(!matrix.empty()){
            dp = matrix;
            size_t row_size = dp.size();
            size_t col_size = dp[0].size();
            for(int index = 1; index < col_size; ++index)
                dp[0][index] += dp[0][index - 1];
            for(int index = 1; index < row_size; ++index)
                dp[index][0] += dp[index - 1][0];
            for(int index_i = 1; index_i < row_size; ++index_i){
                for(int index_j = 1; index_j < col_size; ++index_j){
                    dp[index_i][index_j] = matrix[index_i][index_j]
                            + dp[index_i - 1][index_j]
                            + dp[index_i][index_j - 1]
                            - dp[index_i - 1][index_j - 1];
                }
            }
        }
        }
        
        int sumRegion(int row1, int col1, int row2, int col2) {
            int ret = 0;
        if(row1 > row2 || col1 > col2) return 0;
        if(row1 == row2 && col1 == col2){
            if(0 == row1 && 0 == col1)
                ret = dp[0][0];
            else if(0 == row1)
                ret = dp[row2][col2] - dp[row2][col2 - 1];
            else if(0 == col1)
                ret = dp[row2][col2] - dp[row2 - 1][col2];
            else
                ret = dp[row2][col2] - dp[row2 - 1][col2] - dp[row2][col2 - 1] + dp[row2 - 1][col2 - 1];
        } else{
            if(0 == row1 && 0 == col1)
                ret = dp[row2][col2];
            else if(0 == row1)
                ret = dp[row2][col2] - dp[row2][col1 - 1];
            else if(0 == col1)
                ret = dp[row2][col2] - dp[row1 - 1][col2];
            else
                ret = dp[row2][col2] - dp[row1 - 1][col2] - dp[row2][col1 - 1] + dp[row1 - 1][col1 - 1];
        }
        return ret;
        }

        vector<vector<int>> dp;
    };

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
```