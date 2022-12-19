![515531AA-CAF4-41A5-B901-31205A2A4BA1.jpeg](https://pic.leetcode-cn.com/acfcda3115d934080a17a2f5e7c4e82a1aea5cf188e87e94a51f8a684bb87e39-515531AA-CAF4-41A5-B901-31205A2A4BA1.jpeg)

```
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
