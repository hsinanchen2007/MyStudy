```
int lengthOfLIS(int* nums, int numsSize){
    if ((nums == NULL) || (numsSize == 0)) {
        return 0;
    }

    int i;
    int j;
    int returnValue = 0;
    int *dp = (int *)malloc(numsSize * sizeof(int));
    memset(dp, 0, numsSize * sizeof(int));
    dp[0] = 1;

    int maxValDp;
    int tmp;
    //printf("dp[0]: %u\n", dp[0]);

    for (i = 1; i < numsSize; i++) {
        dp[i] = 1;
        for (j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
            }
        }
        //printf("dp[%u]: %u\n", i, dp[i]);
        returnValue = dp[i] > returnValue ? dp[i] : returnValue;
    }

    return dp[0] > returnValue ? dp[0] : returnValue;
}
```
