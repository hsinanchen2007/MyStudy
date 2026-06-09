```
import java.util.Arrays;

class Solution {
    public int longestLine(int[][] M) {
        if(M.length==0||M[0].length==0) return 0;
        int max = 0;
        //扫描行
        for(int i=0;i<M.length;i++) {
            int n = 0;
            for(int j=0;j<M[0].length;j++) {
                if(M[i][j]==1) n++;
                else {
                    if(n>max) max = n;
                    n = 0;
                }
            }
            if(n>max) max = n;
        }
        //扫描列
        for(int j=0;j<M[0].length;j++) {
            int n = 0;
            for(int i=0;i<M.length;i++) {
                if(M[i][j]==1) n++;
                else {
                    if(n>max) max = n;
                    n = 0;
                }
            }
            if(n>max) max = n;
        }

        //扫描对角线
        int[][] dp = new int[M.length][M[0].length];
        for(int i=0;i<M.length;i++) dp[i][0] = M[i][0];
        for(int j=0;j<M[0].length;j++) dp[0][j] = M[0][j];
        for(int i=1;i<M.length;i++) {
            for(int j=1;j<M[0].length;j++) {
                if(M[i][j]==1) dp[i][j] = dp[i-1][j-1]+1;
            }
        }
        for(int i=0;i<dp.length;i++) {
            for(int j=0;j<dp[0].length;j++) {
                if(dp[i][j]>max) max = dp[i][j];
            }
        }
        
        //扫描反对角线
        for(int[] row:dp) Arrays.fill(row,0);
        for(int i=0;i<dp.length;i++) dp[i][dp[0].length-1] = M[i][dp[0].length-1];
        for(int j=0;j<dp[0].length;j++) dp[0][j] = M[0][j];
        for(int i=1;i<M.length;i++) {
            for(int j =0;j<M[0].length-1;j++) {
                if(M[i][j]==1) dp[i][j] = dp[i-1][j+1]+1;
            }
        }
        for(int i=0;i<dp.length;i++) {
            for(int j=0;j<dp[0].length;j++) {
                if(dp[i][j]>max) max = dp[i][j];
            }
        }

        return max;
    }
}
```
