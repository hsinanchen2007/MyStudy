```
int massage(int* nums, int numsSize){
    if(numsSize == 0) {
        return 0;
    }
    if(numsSize == 1) {
        return nums[0];
    }

    int* dp = (int*)malloc(sizeof(int) * numsSize);
    int i;
    int max = 0;
    dp[0] = nums[0];
    dp[1] = fmax(nums[0], nums[1]);

    for(i = 2; i < numsSize; i++) {
        dp[i] = fmax(dp[i - 1], dp[i - 2] + nums[i]);
    }

    for(i = 0; i < numsSize; i++) {
        max = fmax(max, dp[i]);
    }
    return max;
}
```
