执行用时 :4 ms, 在所有 C 提交中击败了97.46% 的用户
内存消耗 :7.3 MB, 在所有 C 提交中击败了81.92%的用户
### 解题思路
![演示文稿1.jpg](https://pic.leetcode-cn.com/bff342974667a3c206416070d3a242ef01fd40d89485c11cedb4a0aeee15b67f-%E6%BC%94%E7%A4%BA%E6%96%87%E7%A8%BF1.jpg)

memset函数将数组所有元素初始化为0
动态规划 用一个一维数组记录上一行的结果：
`dp[m][n] = dp[m-1][n] + dp[m][n-1];` 变成了 `dp[m] = dp[m] + dp[m-1];`

### 代码

```c
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    long *arr = (long *)malloc(sizeof(long) *(obstacleGridColSize[0]+1));
    memset(arr,0,sizeof(long) *(obstacleGridColSize[0]+1));
    arr[1] = 1;

    for(int j=1;j<=obstacleGridSize;j++)
        for(int k=1;k<=obstacleGridColSize[j-1];k++)
            if (obstacleGrid[j-1][k-1]==1)arr[k] = 0;
            else arr[k] += arr[k-1];
    return arr[*obstacleGridColSize];
}
```