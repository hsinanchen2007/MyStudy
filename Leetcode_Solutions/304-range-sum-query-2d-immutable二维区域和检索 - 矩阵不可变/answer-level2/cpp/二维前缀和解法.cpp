
![image.png](https://pic.leetcode-cn.com/51a19bc7710c2ab276a1ca705e255925799db5b6725c11d1c2aef9d51fbdee91-image.png)
区域和就是黑框框的和，即右下的前缀和减去橙色，红色，绿色的部分(求这个几个颜色的和与前缀和的状态转移方程分析过程类似)。
```c++
class NumMatrix {
public:
    vector<vector<int>>dp;
    int n=0,m=0;
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        if(n)
            m=matrix[0].size();
        dp = vector(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(!n)return 0;
        return dp[row2+1][col2+1]-dp[row1][col2+1]-dp[row2+1][col1]+dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
```