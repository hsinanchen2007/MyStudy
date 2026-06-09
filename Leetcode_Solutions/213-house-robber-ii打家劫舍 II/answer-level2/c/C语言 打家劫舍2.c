

```bash

int rob1(int* nums, int numsSize){

    if (numsSize == 0 || nums == NULL) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }

    int dp[numsSize];
    dp[0] = nums[0];
    dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];

    int i = 0;
    for(i = 2; i < numsSize; i++) {
        dp[i] = dp[i - 1] > dp[i - 2] + nums[i] ?  dp[i - 1] : dp[i - 2] + nums[i];
    }

    return dp[i - 1];
}


int rob(int* nums, int numsSize){
    //printf("numsSize = %d\n", numsSize);

    if (numsSize == 0 || nums == NULL) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }

    int sum1 = rob1(nums + 1, numsSize - 1);
    //printf("sum1 = %d\n", sum1);
    int sum2 = rob1(nums, numsSize - 1);
    //printf("sum2 = %d\n", sum2);

    return sum1 > sum2 ? sum1 : sum2;
}
```