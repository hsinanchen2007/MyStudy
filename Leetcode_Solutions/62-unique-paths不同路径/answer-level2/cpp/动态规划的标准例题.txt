**动态规划**
   设计二维的动态数组dp，dp[i][j]表示在（0,0）到（i，j）的路径条数。根据题意初始化，（0,0）显然为1，因为机器人智能向右和向下，所以（i，0）和（0，j）的路径条数都为1。得到动态归回的递推式dp[i][j] = dp[i-1][j]+dp[i][j-1]。接下来的工作也就不用多说！

class Solution {
public:
    
    int uniquePaths(int m, int n) {
        if(m==0||n==0) return 0;
        int dp[m][n];
        dp[0][0] = 1;
        for(int i=0;i<m;i++){
            dp[i][0] = 1;
        }
        for(int j = 0;j<n;j++){
            dp[0][j] = 1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
   
};

