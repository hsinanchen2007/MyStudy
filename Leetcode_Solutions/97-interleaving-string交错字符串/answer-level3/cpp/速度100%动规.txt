维护一个(m+1)*(n+1)的dp
这是一个二维动规问题，可以看作s1的前i个字符和s2的前j个字符是否可以构成s3的前i+j个字符
注意因为要维护初始行和列，因此下标访问涉及一些调整
如果上一行为1且s1[i-1]等于s3[i+j-1]或者上一列为1且s2[j-1]等于s3[i+j-1]则dp[i][j]就为1，其他情况为0
初始化第一行和第一列时注意，dp[0][0]=1,因为空的s1和空的s2可以构成空的s3
```
class Solution {
public:
 bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        int t = s3.length();
        if(t!=m+n)return false;
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=m;i++){
            if(s3[i-1]==s1[i-1]&&dp[i-1][0]==1){
                dp[i][0]=1;
            }
            else{
                dp[i][0]=0;
            }
        }
        for(int j=1;j<=n;j++){
            if(s3[j-1]==s2[j-1]&&dp[0][j-1]==1){
                dp[0][j]=1;
            }
            else {
                dp[0][j]=0;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(dp[i-1][j]==1&&s3[i+j-1]==s1[i-1]){
                    dp[i][j]=1;   
                }
                else if(dp[i][j-1]==1&&s3[i+j-1]==s2[j-1]){
                    dp[i][j]=1;
                }
                else {
                    dp[i][j]=0;
                }
            }
        }
        return dp[m][n];
    }
};
```