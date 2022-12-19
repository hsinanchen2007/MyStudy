### 解题思路
dp[i] = max{dp[i - 1], dp[i - 2] + nums[i]}
因为环形限制头尾不能全偷所以两次DP， 第一次[0, len - 1]， 第二次[1, len]取两次结果最大值

### 代码

```c

int max(int a, int b) {
    return a > b ? a : b;
}

int rob(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    if (numsSize == 2) {
        return max(nums[0], nums[1]);
    }
    int dp[numsSize];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < numsSize - 1; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    int ans = dp[numsSize - 2];

    dp[1] = nums[1];
    dp[2] = max(nums[1], nums[2]);
    for (int i = 3; i < numsSize; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    ans = max(ans, dp[numsSize - 1]);
    return ans;
}
```