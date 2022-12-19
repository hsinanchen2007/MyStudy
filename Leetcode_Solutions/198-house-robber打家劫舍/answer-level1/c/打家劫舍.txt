```
#define MAX(a,b) ((a) > (b) ? (a) : (b))
int rob(int* nums, int numsSize){
    if(numsSize == 0) {
        return 0;
    }
    
    int* dp = (int*)malloc(sizeof(int)*(numsSize + 1));
    dp[0] = 0;
    dp[1] = nums[0];
    
    for(int i = 2;i <= numsSize;i++) {
        dp[i] = MAX(dp[i-1],dp[i-2] + nums[i-1]);
    }
    
    return dp[numsSize];
}
```
