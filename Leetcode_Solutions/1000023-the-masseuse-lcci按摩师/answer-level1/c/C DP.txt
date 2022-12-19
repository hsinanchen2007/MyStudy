### 解题思路
动态规划，定义dp[i]表示从开始到当前时间段可以按摩的最长总时间。那么就有两种可能：
1）选择当前时间段按摩，那么就是前面倒数第二个总时间加上当前时间，dp[i] = dp[i - 2] + nums[i]；
2）选择当前时间段休息，那么就等于前面倒数第一个总时间，dp[i] = dp[i - 1]；
最终，每次都是取上述两种情况的最大值，即max（dp[i - 2] + nums[i]，dp[i - 1]），最后一个dp[i]就是总的最长时间。

### 代码

```c
#define MAX(x, y) ((x) > (y))?(x):(y)

int massage(int* nums, int numsSize) {
    int *dp = (int *)malloc(sizeof(int) * numsSize);
    int i;
    for (i = 0; i < numsSize; i++) {
        dp[i] = 0;
    }
    if (numsSize == 0) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    } 

    if (numsSize == 2) {
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }

    dp[0] = nums[0];
    dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];

    for (i = 2; i < numsSize; i++) {
        dp[i] = MAX(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[i - 1];
}
```