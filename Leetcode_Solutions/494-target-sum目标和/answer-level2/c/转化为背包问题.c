
对于这种加减法问题，变成2堆就能转化成纯加法问题了

```
int findTargetSumWays(int* nums, int numsSize, int S)
{
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if ((sum - S) % 2 != 0 || S > sum) return 0;
    int aim = (sum - S) / 2;
    int dp[aim + 1];
    memset(&dp, 0, sizeof(int) * (aim + 1));
    dp[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = aim; j >= nums[i]; j--) {
            dp[j] = dp[j] + dp[j - nums[i]];
        }
    }
    return dp[aim];
}
```
