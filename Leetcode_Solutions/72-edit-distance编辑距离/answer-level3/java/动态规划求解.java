```
class Solution {
    public int minDistance(String word1, String word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        /* 举例理解状态转移方程
           如：A:"horse" B:"ros"，dp[a][b]为其中一个过程值，如："hor"到 "ro"，
           若A中下一个的字符和B中下一个字符相同，如举例中所示，即都是"s"，则不需要进行操作，直接dp[a+1][b+1] = dp[a][b];
           否则：dp[a+1][b] = dp[a][b]+1；删除一个字符
                 dp[a][b+1] = dp[a][b]+1；插入一个字符
                 dp[a+1][b+1] = dp[a][b]+1；替换一个字符
            取其中最小的，即可得到dp[a+1][b+1] = min{dp[a][b],dp[a+1][b],dp[a][b+1]}+1
        */
        
        int[][] dp = new int[n1 + 1][n2 + 1];
        dp[0][0] = 0;
        // 初始化
        for(int k = 1;k <= n1 || k <= n2;k++){
            if(k <= n1){
                dp[k][0] = k;
            }
            if(k <= n2){
                dp[0][k] = k;
            }
        }
        
        // 求解
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)){
                    dp[i][j] = dp[i - 1][j - 1];
                }  
                else {
                    dp[i][j] = getMin(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1;
                }
            }
        }
        return dp[n1][n2];
    }
    
    public int getMin(int ...args){
        int min = args[0];
        for(int i = 1;i < args.length;i++){
            min = (min <= args[i])? min : args[i];
        }
        return min;
    }
}
```
