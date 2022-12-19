```
class Solution {
    // 动态规划
    public int maximalSquare(char[][] matrix) {
        if (matrix.length == 0)
            return 0 ;
        if (matrix.length == 1 && matrix[0].length == 0)
            return 0 ;
        int ret = 0 ;
        int[][] dp = new int[matrix.length][matrix[0].length] ;
        for (int i=0 ; i< matrix.length ;i++) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0 ;
            ret = Math.max(ret ,dp[i][0]) ;
        }

        for (int j=0 ; j< matrix[0].length ;j++) {
            dp[0][j] = matrix[0][j] == '1' ? 1 : 0 ;
            ret = Math.max(ret ,dp[0][j]) ;
        }
        for (int i=1 ; i< matrix.length ;i++ ) {
            for (int j=1 ;j<matrix[0].length ; j++) {
                if (matrix[i][j]=='1') {
                    dp[i][j] = Math.min(
                        Math.min(dp[i][j-1] ,dp[i-1][j-1]),
                        dp[i-1][j] ) + 1 ;
                    ret = Math.max(ret ,dp[i][j]) ;
                }
            }
        }
        return ret * ret ;
    }
}
```
