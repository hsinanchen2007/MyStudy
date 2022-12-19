**把矩形分割成几个小矩形差值即可**

```
class NumMatrix {
public:
/*dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
    * e=dp[i1][j]+dp[i][j1]-dp[i1][j1];
    * re=dp[i][j]-e;
    */
    int dp[200][200];
    int n=0,m=0;
    NumMatrix(vector<vector<int>>& matrix) {
         if(!matrix.empty())n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<=m;i++)dp[0][i]=0;//初始化一下行边界
        for(int i=0;i<=n;i++)dp[i][0]=0;//初始化一下列边界
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=dp[row2+1][col2+1],e=dp[row1][col2+1]+dp[row2+1][col1]-dp[row1][col1];
        return ans-e; 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
```
数据确实太弱了。。。
另外可以优化成滚动数组：节省下空间
