类似于青蛙跳的标准dp题
dp[i][j] = dp[i][j-1] + dp[i-][j] 
对于两条边的处理，我一开始使用两个循环初始化两条边，结果发现用时只有50%
后来试了一下不初始化两条边，把对边的处理直接放在dp循环体中，成功100%，不过我个人感觉还是初始化的方式看的条理清晰一点


1ms 50%
```
class Solution {
    public int uniquePaths(int m, int n) {
        if( m == 0 || n == 0 )return 0;
        int[][] dp = new int[m][n];
        dp[0][0] = 1;
        for(int i=0; i<m; i++){
            dp[i][0] = 1;
        }
        for(int j=0; j<n; j++){
            dp[0][j] = 1;
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
}
```


0ms 100%
```
class Solution {
    public int uniquePaths(int m, int n) {
        if( m == 0 || n == 0 )return 0;
        int[][] dp = new int[m][n];
        dp[0][0] = 1;
       
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0)continue;
                if(i>0 && j==0){
                    dp[i][j] = dp[i-1][j];
                }else if(j>0 && i==0)  {
                    dp[i][j] = dp[i][j-1];
                }
                else{
                     dp[i][j] = dp[i][j-1]+dp[i-1][j];;
                }      
            }
        }

        return dp[m-1][n-1];
    }
}
```


