### 解题思路
此处撰写解题思路

dp[i]表示以i结尾的最高值，则动态方程为：
dp[i] = MAX_HTL(dp[i - 1], dp[i - 2] +  nums[i]);

### 代码

```c
#define MAX_HTL(a, b) ((a) > (b) ? (a) : (b))

int massage(int* nums, int numsSize){
    int *dp = (int *)malloc(sizeof(int) * numsSize);
    int i, res;

    if (nums == NULL || numsSize <= 0) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }

    if (numsSize == 2) {
        return MAX_HTL(nums[0], nums[1]);
    }

    dp[0] = nums[0];
    dp[1] = MAX_HTL(nums[0], nums[1]);

    for (i = 2; i < numsSize; i++) {
        dp[i] = MAX_HTL(dp[i - 1], dp[i - 2] +  nums[i]);
    }

    res = dp[numsSize - 1];
    free(dp);

    return res;
}
```