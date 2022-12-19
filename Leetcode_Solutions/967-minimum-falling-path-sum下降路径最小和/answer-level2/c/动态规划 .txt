### 解题思路
动态规划，先设定基础值，根据下述公式计算每一个参数对应的最小路径，最后在最后一层里搜索最小的值即为最终结果:
c1 = min((dp[i-1][j] + A[i][j]), (dp[i-1][j-1] + A[i][j]));
c2 = min((dp[i-1][j] + A[i][j]), (dp[i-1][j+1] + A[i][j]));
dp[i][j] = min(c1, c2);

### 代码

```c
#define min(x, y) (x < y ? x : y)
int minFallingPathSum(int** A, int ASize, int* AColSize){
    double dp[ASize][(*AColSize)];
    memset(dp, 0, ASize*(*AColSize)*sizeof(int));
    double c1 = 0;
    double c2 = 0;
    int c3;
    for(int j = 0; j < (*AColSize); j++) {
        dp[0][j] = A[0][j];
    }

    for(int i = 1; i < ASize; i++) {
        for(int j = 0; j < (*AColSize); j++) {
            if(j == 0) {
                if(j+1 < (*AColSize)) {
                    dp[i][j] = min((dp[i-1][j] + A[i][j]), (dp[i-1][j+1] + A[i][j]));
                } else {
                    dp[i][j] = dp[i-1][j] + A[i][j];
                }
            } else if(j == (*AColSize)-1) {
                dp[i][j] = min((dp[i-1][j] + A[i][j]), (dp[i-1][j-1] + A[i][j]));
            } else {
                c1 = min((dp[i-1][j] + A[i][j]), (dp[i-1][j-1] + A[i][j]));
                c2 = min((dp[i-1][j] + A[i][j]), (dp[i-1][j+1] + A[i][j]));
                dp[i][j] = min(c1, c2);
            }
        }
    }
    c3 = dp[ASize-1][0];
    for(int k = 0; k < (*AColSize); k++) {
        c3 = min(c3, dp[ASize-1][k]);
    }
    return c3;

}
```