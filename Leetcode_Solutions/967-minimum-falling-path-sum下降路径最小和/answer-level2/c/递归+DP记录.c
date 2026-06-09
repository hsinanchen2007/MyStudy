### 解题思路
f(col, row) = val + MIN(f(col + 1, row -1), f(col + 1, row), f(col + 1, row + 1))

然后第一行每个元素计算一遍f(), 结果就是MIN(f(0~ASize))

如果直接这样写，会超时，所以增加一个dp[][]记录已有结果加快速度


### 代码

```c
#include <limits.h>
int MIN(int a, int b, int c)
{
    int tmp = a < b ? a : b;
    return tmp < c ? tmp : c;
}
int MIN_2(int a, int b)
{
    return a < b ? a : b;
}

int fallingPathSum(int **A, int ASize, int col, int row, int (*dp)[100])
{
    if (row < 0 || row > ASize - 1) return INT_MAX;
    int result = 0;
    if (dp[col][row]) return dp[col][row];
    if (col == ASize - 1) {
        dp[col][row] = A[col][row];
        return A[col][row];
    }
    int a = fallingPathSum(A, ASize, col + 1, row - 1, dp);
    int b = fallingPathSum(A, ASize, col + 1, row    , dp);
    int c = fallingPathSum(A, ASize, col + 1, row + 1, dp);
    result = A[col][row] + MIN(a, b, c);
    dp[col][row] = result;
    return result;
}

int minFallingPathSum(int** A, int ASize, int* AColSize){
    int dp[100][100] = {0};
    int result = INT_MAX;
    for (int i = 0; i < ASize; i ++) {
        result = MIN_2(result, fallingPathSum(A, ASize, 0, i, dp));
    }
    return result;
}

```