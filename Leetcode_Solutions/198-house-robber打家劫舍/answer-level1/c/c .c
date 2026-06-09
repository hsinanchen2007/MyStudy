### 解题思路
此处撰写解题思路

### 代码

```c
/*
1
dp[N][0] 不偷第N 间money for steal N house
dp[N][1] 偷第N间

 dp[N][0] = MAX(dp[N-1][0], dp[N-1][1])
 dp[N][1] = dp[N-1][0] + v[N]   

 dp[0][0] = 0;
 dp[0][1] = v[0];
2,
dp[N] 第N次的money

dp[i] = MAX(dp[i-1], dp[i-2] + nums[i])

*/
#define MAX(a, b) ((a>b) ? (a) : (b))
int dp[50000];
int rob(int* nums, int numsSize){
    if(nums==NULL || numsSize==0) {
        return 0;
    }
#if 0   
    dp[0][0] = 0;
    dp[0][1] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        dp[i][0] =  MAX(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + nums[i];
    }
    int max = MAX(dp[numsSize-1][0],dp[numsSize-1][1]);
#endif
    if (numsSize == 1) {
        return nums[0];
    }
    dp[0] = nums[0];
    dp[1] = MAX(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++) {
        dp[i] = MAX(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[numsSize-1];

}
```