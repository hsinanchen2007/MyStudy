### 解题思路
实际本题可以使用dfs/bfs，这两个都可以，但使用的时候会有用例不过，原因就是没有使用剪枝，如果结合适当的visit剪枝，使用dfs/bfs也是可以过的。
动态规划也一样可以解本题，思路也比较简单；
由于只能向右、向下走，所以第一行与第一列初始化为1，因第一行只能向右走，第一列只能向下走，都只有一种走法；但需要注意的是，如果遇到障碍则在障碍处写0，代表无法通过；
其它的dp[i][j] = dp[i][j - 1] + dp[i - 1][j];即可
![123.PNG](https://pic.leetcode-cn.com/9ea808a379a00e727aac317204bc7de0a716c830cba48d9e1bf5be5d8ce42a23-123.PNG)


### 代码

```c
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    unsigned int **dp = NULL;
    int i, j;
    dp = (int **)malloc(sizeof(int *) * obstacleGridSize);
    for (i = 0; i < obstacleGridSize; i++) {
        dp[i] = (int *)malloc(sizeof(int) * (*obstacleGridColSize));
        memset(dp[i], 0, sizeof(int) * (*obstacleGridColSize));
    }
    int flag = 1; // init the first row
    for (i = 0; i < *obstacleGridColSize; i++) {
        if (obstacleGrid[0][i] == 0) {
            dp[0][i] = flag;
        } else {
            flag = 0;
        }
    }
    flag = 1; // init the first colomn
    for (i = 0; i < obstacleGridSize; i++) {
        if (obstacleGrid[i][0] == 0) {
            dp[i][0] = flag;
        } else {
            flag = 0;
        }
    }
    for (i = 1; i < obstacleGridSize; i++) {
        for (j = 1; j < *obstacleGridColSize; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }
    return dp[obstacleGridSize - 1][*obstacleGridColSize - 1];
}
```