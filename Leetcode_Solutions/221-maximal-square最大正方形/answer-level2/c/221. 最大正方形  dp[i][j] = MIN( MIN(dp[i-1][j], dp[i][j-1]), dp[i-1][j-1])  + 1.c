### 解题思路
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4



按照官方题解里两个方格示意图，   动态规划找出最大正方形边长。

注意C语言里 分配二维数组的用法
### 代码

```c
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){

    /*二维上都多分配一个长度*/
    int **dp = (int **)malloc((matrixSize+1) * sizeof(int *));
    int i, j, max = 0;
   
    if(matrixSize == 0 || matrix ==NULL)
        return 0;

    for(i=0; i < (matrixSize+1); i++) {
        dp[i] = (int *)malloc((matrixColSize[0] + 1)*sizeof(int));
        /*这里需要置0下，不然下面取值对比可能是异常值*/
        memset(dp[i], 0, (matrixColSize[0] + 1)*sizeof(int));
    }

    /*下面要减，故i从1开始, matrix[i-1][j-1]保证依旧从0开始遍历，所以for循环里i <=*/
    for(i=1;i<=matrixSize;i++){
        for(j=1; j <=matrixColSize[0]; j++) {
            if(matrix[i-1][j-1] == '1'){
                dp[i][j] = MIN( MIN(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) +1;
                if(dp[i][j] > max)  
                    max = dp[i][j];
            }
        }
    }

    return max*max;
}
```