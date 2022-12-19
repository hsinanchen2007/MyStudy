```
class Solution {
    public int maximalSquare(char[][] matrix) {
        int row = matrix.length;
        if(row==0)
            return 0;
        int col = matrix[0].length;
        int[][] dp = new int[row+1][col+1];
        int max = 0;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                if(matrix[i-1][j-1]=='1'){
                    //如果该点左边和上边和左上三点都满足，说明是正方形。否则选最小的
                    int left_or_top = Math.min(dp[i-1][j],dp[i][j-1]);
                    int min = Math.min(left_or_top,dp[i-1][j-1])+1;
                    dp[i][j] = min;
                    max = Math.max(min,max);
                }
            }
        }
        return max*max;
    }
}
```
