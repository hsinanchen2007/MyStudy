```
int lengthOfLIS(int* nums, int numsSize){
    int i, j;
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    int maxlen = 0;

    for(i = 0; i < numsSize; i++) {
        dp[i] = 1;
    }

    for(i = 0; i < numsSize; i++) {
        for(j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
    }

    for(i = 0; i < numsSize; i++) {
        maxlen = fmax(maxlen, dp[i]);
    }
    return maxlen;
## }
```
