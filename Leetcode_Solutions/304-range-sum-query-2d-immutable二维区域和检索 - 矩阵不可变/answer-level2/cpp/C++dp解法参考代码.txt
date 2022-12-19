```
class NumMatrix {
private:
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        dp = std::move(matrix);
        if(dp.size() == 0)  return;
        for(int i = 1; i < dp[0].size(); i++)
            dp[0][i] = dp[0][i] + dp[0][i-1];
        for(int i = 1; i < dp.size(); i++)
            dp[i][0] = dp[i][0] + dp[i-1][0];
        for(int i = 1; i < dp.size(); i++){
            for(int j = 1; j < dp[0].size(); j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + dp[i][j];
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(!row1 && !col1)
            return dp[row2][col2];
        else if(row1 && !col1)
            return dp[row2][col2]-dp[row1-1][col2];
        else if(col1 && !row1)
            return dp[row2][col2]-dp[row2][col1-1];
        else
            return dp[row2][col2]-dp[row1-1][col2]-dp[row2][col1-1]+dp[row1-1][col1-1];
    }
};
```
