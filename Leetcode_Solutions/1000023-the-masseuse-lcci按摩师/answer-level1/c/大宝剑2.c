### 解题思路
贪心动态规划

### 代码

```c
/*
    动态规划
    dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
*/

#define MAXCOMPARESIZE(x, y) (x > y ? x : y)

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int massage(int* nums, int numsSize){
    if ((nums == NULL) || (numsSize == 0)) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }

    int *dp = (int *)malloc(numsSize * sizeof(int));
    memset(dp, 0, numsSize * sizeof(int));

    dp[0] = nums[0];
    dp[1] = MAXCOMPARESIZE(nums[0], nums[1]);

    int i;
    for (i = 2; i < numsSize; i++) {
        dp[i] = MAXCOMPARESIZE(dp[i - 1], dp[i - 2] + nums[i]);
    }
    qsort(dp, numsSize, sizeof(dp[0]), cmp);

    return dp[0];
}
```