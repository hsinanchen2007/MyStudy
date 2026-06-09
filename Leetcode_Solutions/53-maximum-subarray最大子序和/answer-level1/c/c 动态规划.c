#define MYMAX(a, b) ((a) > (b) ? (a) : (b))
int maxSubArray(int* nums, int numsSize){
    int *dp = calloc(numsSize, sizeof(int));
    int i;
    int sum = 0;
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    dp[0] = nums[0];
    sum  = dp[0];
    for (i = 1; i < numsSize; i++) {
        dp[i] = MYMAX(dp[i-1], 0) + nums[i];
        sum = MYMAX(sum, dp[i]);
    }
    return sum;
}