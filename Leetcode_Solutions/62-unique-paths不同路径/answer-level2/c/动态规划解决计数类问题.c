### 解题思路
    /* 
     * 1. 使用动态规划解决计数类问题，确定状态:
         dp[m][n] = 从左上角有多少条路径走到m x n
     * 2. 从最后一步看，只能从(m-1, n)往下走，或者从(m, n-1)往右走。写出转移方程：
     *   dp[m][n] = dp[m-1][n] + dp[m][n-1]
     *   也可以看出被分解为两个子问题，(m-1) x n 或者 (m) x (n-1)的最下角
     * 3. 初始值以及边界条件：
          dp[0][0] = o
     *    第1行或者第1列只有一种走法
     *    dp[0][*] = 1
     *    dp[*][0] = 1
     * 4. 计算顺序：逐行从左往右计算
     */
### 代码

```c
int uniquePaths(int m, int n){
    int result;
    /* 一维数组当二维来用 */
    int *dp = (int *) malloc(m * n * sizeof(int));
     for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
             if (i == 0 || j == 0) {
                 dp[i * n + j] = 1;
                 continue;
            }
            dp[i * n + j] = dp[(i-1)*n + j] + dp[i*n + j-1];
        } 
    }
    result = dp[m * n - 1];
    free(dp);
    return result;
}
```