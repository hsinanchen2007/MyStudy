### 解题思路
动态规划，题目可以等价于从原点（0,0）到达终点（m-1,n-1）的不同路径。dp（x,y）代表从原点达到(x,y)点的不同路径。
初始状态，到达（x,0）和（0，y）的路径又有1。
dp(x, y) = dp(x-1,y)+dp(x,y-1) 即到达(x,y)点的不同路径等于到达相邻两个点(x-1,y)/(x,y-1)的路径之和

### 代码

```c

/** dp[m,n] = dp[m-1,n]+dp[m,n-1];
*   dp[0,0] = 0;
*   dp[x,0] = 1; dp[0,y]=1;
*/

int uniquePaths(int m, int n){
    int dp[100][100];
    int x = 0;
    int y = 0;

    while (x < m) {
        dp[x++][0] = 1;
    }
    while (y < n) {
        dp[0][y++] = 1;
    }

    for (x = 1; x < m; x++) {
        for (y = 1; y < n; y++) {
            dp[x][y] = dp[x-1][y] + dp[x][y-1];
        }
    }
    return dp[m-1][n-1];

}


```