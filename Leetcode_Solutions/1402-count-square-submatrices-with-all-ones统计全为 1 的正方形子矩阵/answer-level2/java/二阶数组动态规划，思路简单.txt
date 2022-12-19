动态规划递推公式：
*dp[i][j] = Math.min(dp[i-1][j-1],Math.min(dp[i-1][j],dp[i][j-1]))+1*
意思就是以当前点为右下角的正方形的最大边长= 上面的点，左面的点，斜对角的点 的边长的最小值+1

首先要处理最上面和最左面的边界情况，然后遍历时跳过0点

最后将dp数组求和

```
public int countSquares(int[][] matrix) {
        int xlen = matrix.length;
        int ylen = matrix[0].length;
        int[][] dp = new int[xlen][ylen];

        //处理最上面和最左面的边界情况
        for(int i=0 ; i<xlen ; i++){
            dp[i][0] = matrix[i][0]==1 ? 1 : 0;
        }
        for(int i=0 ; i<ylen ; i++){
            dp[0][i] = matrix[0][i]==1 ? 1 : 0;
        }
        
        for(int i=1 ; i<xlen ; i++){
            for(int j=1 ; j<ylen ; j++){
                //跳过0点
                if(matrix[i][j]==0) continue;
                //递推
                dp[i][j] = Math.min(dp[i-1][j-1],Math.min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
        
        int res = 0;
        for(int i=0 ; i<xlen ; i++){
            for(int j=0 ; j<ylen ; j++){
                res += dp[i][j];
            }
        }
        return res;
    }
```
