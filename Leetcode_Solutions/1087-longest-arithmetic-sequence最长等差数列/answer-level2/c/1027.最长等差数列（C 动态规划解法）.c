题解：
dp[i][diff]表示以数组第i个元素为等差数列的最后一个元素时的数列长度，其中diff为等差数列的等差。

特殊情况：
dp[0][diff] = 0, 其中0 <= diff < 20000
dp[1][diff] = 2,其中diff == A[1] - A[0] + 10000.diff加10000，是因为要做数组下表，要转化成一个合法值
dp[2][diff20] = 2  等价于 dp[2][diff20] = dp[0][diff20] == 0 ? 2 : dp[0][diff20] + 1 
dp[2][diff21] = dp[1][diff21] == 0 ? 2 : diff[1][diff21] + 1, 其中diff21 = A[2] - A[1] + 10000

一般情况：
dp[i][diff] = dp[j][diff] + 1 
其中，0 <= j < i < 2000, diff = A[i] - A[j] + 10000    
因为0 <= A[i] <= 10000，所以0 <= diff < 20000



动态规划思想，就是从最简单的情况逐步推导出一般情况。
```
#define A_MAX_LEN 2000
#define A_MAX_VALUE  10000
#define A_MIN_VALUE  0
#define DIFF_MAX_RANGE 20001

int longestArithSeqLength(int* A, int ASize){
    if (ASize <= 2) {
        return ASize;
    }

    int (*dp)[DIFF_MAX_RANGE]= NULL;
    dp = (int( *)[DIFF_MAX_RANGE])malloc(sizeof(int) * ASize * DIFF_MAX_RANGE);
    dp[0][0] = 1;
    int diff = A[1] - A[0] + A_MAX_VALUE;
    dp[1][diff] = 2;

    int i;
    int j;
    int max = 0;
    for (i = 2; i < ASize; i++) {
        for (j = 0; j < i; j++) {
            diff = A[i] - A[j] + A_MAX_VALUE;
            if (dp[j][diff] == 0) {
                /* 首次添加，长度为2 */
                dp[i][diff] = 2;
            } else {
                dp[i][diff] = dp[j][diff] + 1;
            }
            if (max < dp[i][diff]) {
                max = dp[i][diff];
            }
        }
    }
    free(dp);

    return max;
}
```
