```java
/*
dp[i][j]表示s的前i个和p的前j个能否匹配上
总得来说分为4种情况
case1 s[i-1]==p[j-1]
    dp[i][j] = dp[i-1][j-1]
case2 p[j-1]=='.'
    dp[i][j] = dp[i-1][j-1]
case3 p[j-1]=='*'
    等于*是需要考虑较多的一种情况，判断需要多少个p[j-2]
    if s[i-1] != p[j-2] && p[j-2] != '.' 说明s最后一个和p的倒数第二个不能做匹配
        dp[i][j] = dp[i][j-2]
    else if s[i-1]==p[j-2] || p[j-2]=='.'  可以选择匹配0个、1个或多个
        dp[i][j] = dp[i][j-2] || dp[i][j-1] || dp[i-1][j]

case4 
    dp[i][j] = false

*/

class Solution {
    public boolean isMatch(String s, String p) {
        if(s==null || p==null){
            return false;
        }
        int n = s.length();
        int m = p.length();
        boolean[][] dp = new boolean[n+1][m+1];
        //base case
        dp[0][0] = true;
        for(int j=1;j<=m;j++){
            if(p.charAt(j-1)=='*'){
                dp[0][j] = dp[0][j-2];
            }
        }
        //
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s.charAt(i-1)==p.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1];
                } else if(p.charAt(j-1)=='.'){
                    dp[i][j] = dp[i-1][j-1];
                } else if(p.charAt(j-1)=='*'){
                    if(j>=2){
                        if(s.charAt(i-1)==p.charAt(j-2) || p.charAt(j-2)=='.'){
                            dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i][j-2];
                         } else {
                            dp[i][j] = dp[i][j-2];
                         }
                    } 
                }
            }
        }
        return dp[n][m];
    }
}




```
