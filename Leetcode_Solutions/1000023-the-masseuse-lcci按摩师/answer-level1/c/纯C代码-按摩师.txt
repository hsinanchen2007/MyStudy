### 解题思路
此处撰写解题思路

### 代码

```c
int massage(int* nums, int numsSize){
    int dp[10000];
    int i = 2;
    int sum = 0;

    if (numsSize < 1) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    }

    dp[0] = nums[0];
    dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];

    while (i < numsSize) {
        sum = dp[i-2] + nums[i];
        dp[i] = sum > dp[i-1] ? sum : dp[i-1];
        i++;
    }

    return dp[numsSize - 1];
}
```