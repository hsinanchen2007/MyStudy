状态转移方程：  dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])

代码如下：

int maxFun(int a, int b) {
    return a > b ? a : b;
}

int massage(int* nums, int numsSize){
    if (nums == NULL || numsSize < 1) {
        return 0;
    }

    int *dp = (int *)malloc(sizeof(int) * numsSize);
    if (dp == NULL) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }

    dp[0] = nums[0];
    dp[1] = maxFun(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++) {
        dp[i] = maxFun(dp[i - 2] + nums[i], dp[i - 1]);
    }

    return dp[numsSize - 1];
}