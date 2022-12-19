```
//这道题跟第72题-最小编辑距离-：很相似
//但这道题只允许删除word1、删除word2,没有替换这个操作
//其实删除word2可以看成插入word1操作，这样就跟72题很像啦
//只不过递推关系要去掉替换这部分！
public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        int[][] dp = new int[m+1][n+1];
        //初始化第一行、第一列,dp[0][0]已经默认为0了
        for(int i=1;i<n+1;i++){
            dp[0][i] = dp[0][i-1] + 1;
        }
        for(int i=1; i<=m; i++){
            dp[i][0]  = dp[i-1][0] + 1;
        }
        //构造DP表，自底向上
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1.charAt(i-1) == word2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    - 这里就是不同之处
                    //dp[i][j] = Math.min(Math.min(dp[i-1][j-1], dp[i-1][j]),dp[i][j-1]) + 1;
                    dp[i][j] = Math.min(dp[i-1][j],dp[i][j-1]) + 1;
                }

            }
        }

        //得到
        return dp[m][n];
    }
```
