以矩阵中每一个点作为正方形右下角点来处理，当该点为1时，以该点为右下角点的最大边长最多比以它的左方、上方和左上方为右下角的正方形边长多1，即如果该点左上的三个点有值为0的点，当前点所在的全为1的正方形最大边长只能为1，所以这时只能取另外三个正方形中最小的正方形边长+1。
用d[i][j]表示以i，j坐标为右下角的正方形最大边则有状态转移方程：
`dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1`

如果以矩阵内某个点为右下角所能获得的正方形的最大边长为n，则以该点为右下角的不同边长正方形个数一定为n，因为正方行的边长为1~n，所以dp[i][j]也表示以该点为正方形右下角所能获得的不同边长的正方形的个数。所以综上，代码只需在LeetCode 221的基础上，统计以各个点为正方形右下角的最大边长之和。
```
 public int countSquares(int[][] matrix) {
        if(matrix == null || matrix.length == 0){
            return 0;
        }
        int M = matrix.length, N = matrix[0].length;
        int[][] dp = new int[M][N];
        for(int i = 0; i < M; i++){
            if(matrix[i][0] == 1){
                dp[i][0] = 1;
            }
        }
        for(int j = 0; j < N; j++){
            if(matrix[0][j] == 1){
                dp[0][j] = 1;
            }
        }
        for(int i = 1; i < M; i++){
            for(int j = 1; j < N; j++){
                if(matrix[i][j] == 1){
                    dp[i][j] = Math.min(dp[i-1][j], Math.min(dp[i][j-1], dp[i-1][j-1]))+1;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(dp[i][j] > 0){
                    res += dp[i][j];
                }
            }
        }
        return res;
    }
```


