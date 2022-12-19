二维动态规划，唯一要注意的是左上角的矩阵被减了两次，所以最后还要加回来一次
```
/*
如果这道题左上角固定为[0,0]那就很简单了，动态规划，dp[i][j]等于以0,0为左上角，i,j为右下角的矩形的和
但这道题左上角是不固定的，因此要做减法*/
class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 0) {
            return;
        }
        
        dp.resize(matrix.size());
        for (int k = 0; k < matrix.size(); ++k) {
            dp[k].resize(matrix[0].size());
        }

        dp[0][0] = matrix[0][0];
        for (int i = 1; i < dp.size(); ++i) {
            dp[i][0] = dp[i - 1][0] + matrix[i][0];
        }

        for (int j = 1; j < dp[0].size(); ++j) {
            dp[0][j] = dp[0][j - 1] + matrix[0][j];
        }

        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[i].size(); ++j) {
                /*左上角的加了2次，最后要减掉重复的那1次*/
                dp[i][j] = matrix[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (dp.size() == 0) {//有空矩阵输入
            return 0;
        }

        int ans = 0;
        if(row1 == 0 && col1 == 0)//有单个元素的矩阵输入
            ans = dp[row2][col2];
        else if(row1 == 0)
            ans =  dp[row2][col2] - dp[row2][col1 - 1];
        else if(col1 == 0)
            ans = dp[row2][col2] - dp[row1 - 1][col2];
        else 
            ans = dp[row2][col2] - dp[row1 - 1][col2] - dp[row2][col1 - 1] + dp[row1 - 1][col1 - 1];
            /*减掉上矩阵(row - 1)，左矩阵(col - 1)，但是上述操作减了左上矩阵(row - 1, col - 1)两次，因此要加回一次*/
        return ans;
    }
};
```
