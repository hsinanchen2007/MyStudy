### 解题思路
参考官方题解

### 代码

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int dp[1001][51];
int splitArray(int* nums, int numsSize, int m){
    int i, j, k;
    long sub[1001];
    memset(sub, 0, sizeof(int)*1000);
    sub[0] = 0;
    for (i = 0 ; i < numsSize; i++) {
        sub[i+1] = sub[i] + nums[i];
    }
    for (i = 0; i <= numsSize; i++) {
        for (j = 0; j <= m; j++) {
            dp[i][j] = 0x7fffffff;
        }
    }
    dp[0][0] = 0;
    for (i = 1; i <= numsSize; i++) {
        for (j = 1; j <=MIN(i, m); j++) {
            for (k = 0; k < i; k++) {
                dp[i][j] = MIN(dp[i][j], MAX(dp[k][j-1], sub[i]- sub[k]));
            }
        }
    }
    return dp[numsSize][m];
}

```