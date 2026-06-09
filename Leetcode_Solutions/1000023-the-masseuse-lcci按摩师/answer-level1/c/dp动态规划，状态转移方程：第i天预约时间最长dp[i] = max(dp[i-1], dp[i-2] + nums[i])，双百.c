//dp动态规划，状态转移方程：第i天预约时间最长dp[i] = max(dp[i-1], dp[i-2] + nums[i])
```
#define MAX(a, b) (a > b ? a: b)
int massage(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    int dp[numsSize];
    for (int i = 0; i < numsSize; i++) {
        if (i == 0) {
            dp[i] = nums[i];
        } else if (i == 1) {
            dp[i] = MAX(nums[0], nums[1]);
        } else {
            dp[i] = MAX(dp[i - 1], dp[i - 2] + nums[i]);
        }  
    }
    return dp[numsSize - 1];
}
```
