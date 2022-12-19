1. 考虑dp代表的含义：每一个方格中的步数；
2. 考虑边界的特殊情况；
3. 考虑中间方格步数与之前的联系：dp[i][j]=dp[i-1][j]+dp[i][j-1];
```
    public int uniquePaths(int m, int n) {
        int[][] dp=new int[m][n];
        //考虑边界
        for(int i=0;i<m;i++) dp[i][0]=1;
        for(int i=0;i<n;i++) dp[0][i]=1;
        //考虑中间
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
```
