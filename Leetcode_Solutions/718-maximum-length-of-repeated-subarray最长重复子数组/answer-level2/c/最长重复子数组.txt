# 思路
    这个题和之前的求最长子序列有些像，但那个不要求是连续的子数组。
    步骤
    1、申请一个二维数组，dp[x][y],用于存放【数组1】A的前x位和【数组2】B的前y位的最长重复子数组
    2、那么当A[x] == B[y]时，说明这是对最长重复子数组的结果有增益的，那么此时的数组A(前x位)和数组B(前y位)的最长重复子数组就是 
        dp[x][y] = dp[x-1][y-1]+1
    3、当A[x] != B[y]时，说明那么目前最长子数组的结果为0，因为要子数组是要求连续的，某一次不想等，他的长度都要归为0，因此
        dp[x][y] = 0;
    4、上面的二维数组存放的是各种情况最长子数组，需要找出其中最大的那个，就是结果
    5、释放空间
    
# 代码
```
int findLength(int* A, int ASize, int* B, int BSize){
    int i = 0;
    int j = 0;
    int max = 0;

    int **dp = (int **)calloc(sizeof(int *), ASize+1);
    for (i = 0; i <= ASize; i++) {
        dp[i] = (int *)calloc(sizeof(int), BSize+1);
    }
    for (i = 1; i <= BSize; i++) {
        for (j = 1; j <= ASize; j++) {
            if (B[i-1] == A[j-1]) {
                dp[i][j] =  1 + dp[i-1][j-1];
            } else {
                dp[i][j] = 0;
            }
            if (dp[i][j] > max) {
                max = dp[i][j];
            }
        }
    }
    for (i = 0; i <= ASize; i++) {
        free(dp[i]);
    }
    free(dp);
    return max;
}
```
