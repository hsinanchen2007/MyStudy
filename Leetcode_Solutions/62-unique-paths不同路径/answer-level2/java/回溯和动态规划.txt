思路1：
就是从最后一格即终点，就是一种方式，向左向上推进，每个左边的或者上面的格子，都是他右边和下面格子数字之和，累加到最左上角的时候为最终结果。
代码非常简洁，但是在执行过程中出现超时的情况。
10	4	1
6	3	1
3	2	1
1	1	1
```
    public int uniquePaths(int m, int n) {
        if(m==1 || n==1){
            return 1;
        }
        return uniquePaths(m-1,n)+uniquePaths(m,n-1);
    }
```

思路二：
上面思路的逆向思维，每一个右边的格子可能的路径都是其相邻左边和上面的格子数字之和。
1	1	1
1	2	3
1	3	6
1	4	10
```
    public int uniquePaths(int m, int n) {
       int[][] dp = new int[m][n];
        for (int i = 0; i < n; i++) dp[0][i] = 1;
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];  
    }
```


