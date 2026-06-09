```
bool increasingTriplet(int* nums, int numsSize){
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    int i, j;

    for(i = 0; i < numsSize; i++) {
        dp[i] = 1;
    }

    for(i = 1; i < numsSize; i++) {
        for(j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
    }

    for(i = 0; i < numsSize; i++) {
        if(dp[i] >= 3) {
            return true;
        }
    }
    return false;
}
```
