  0 1 2 3
0 1 0 0 0
D 1 0 0 0
I 0 1 1 0
D 2 2 1 0
   👇
  0 1 2 3 4
0 1 0 0 0 0
D 1 0 0 0 0 
I 0 1 1 0 0
D 2 2 1 0 0
D 5 3 1 0 0
即状态方程：
if(s[i-1]==D)
    dp[i][j] = (dp[i][j]+dp[i-1][k])%max;   j<=k<i
else
    dp[i][j] = (dp[i][j]+dp[i-1][k])%max;   0<=k<=j-1

代码如下：
class Solution {
    public int numPermsDISequence(String S) {
        int max = 1000000007;
        int m = S.length();
        int [][] dp = new int[m+1][m+1];
        dp[0][0]=1;
        int res =0;
        for(int i=1;i<=m;i++){
            for(int j=0;j<=i;j++){
                if(S.charAt(i-1)=='D'){
                    for(int k=j;k<i;k++){
                        dp[i][j] = (dp[i][j]+dp[i-1][k])%max;
                    }
                }else{
                    for(int k=0;k<=j-1;k++){
                        dp[i][j] = (dp[i][j]+dp[i-1][k])%max;
                    }
                }
            }
        }
        for(int i=0;i<=m;i++){
            res = (res+dp[m][i])%max;
        }
        return res;
    }
}