```c
#define SIZE 50000
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int dp[SIZE];

int massage(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    dp[0] = nums[0];
    dp[1] = MAX(nums[0], nums[1]);
    int i;
    for (i = 2; i < numsSize; ++i) {
        dp[i] = MAX(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[numsSize - 1];
}

```