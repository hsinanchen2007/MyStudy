### 代码

```java
class Solution {
    private int[][]dir = new int[][]{{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    private double[][][] dp;
    private int N;
    public double knightProbability(int N, int K, int r, int c) {
        dp = new double[N][N][K + 1];
        this.N = N;
        return find(K, r, c);
        
    }

    double find (int K, int r, int c) {
        if(r < 0 || r > N - 1 || c < 0 || c > N - 1) return 0;
        if (K == 0) return 1;
        if (dp[r][c][K] != 0) return dp[r][c][K];
        double res = 0;
        for (int i = 0; i < dir.length; i ++) {
            res += 0.125 * find(K - 1, r + dir[i][0], c + dir[i][1]);
        }
        dp[r][c][K] = res;
        return res;
    }
}
```