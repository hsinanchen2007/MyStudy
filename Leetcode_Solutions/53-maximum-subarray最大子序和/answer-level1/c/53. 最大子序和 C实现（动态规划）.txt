### 解题思路
此处撰写解题思路

### 代码

```c
inline int Max(int a, int b)
{
    return a > b ? a : b;
}

void Free(int** dp, int numsSize)
{
    for (int i = 0; i < numsSize; i++) {
        free(dp[i]);
    }
    free(dp);
    return;
}

int maxSubArray(int* nums, int numsSize){
    if (!nums) {
        return 0;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    int mallocSize = sizeof(int) * 2;
    int** dp = (int**)malloc(numsSize * sizeof(int*));
    dp[0] = (int*)malloc(mallocSize);
    dp[0][0] = nums[0];
    dp[0][1] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        dp[i] = (int*)malloc(mallocSize);
        dp[i][0] = Max(dp[i - 1][0] + nums[i], nums[i]);
        dp[i][1] = Max(dp[i - 1][0], dp[i - 1][1]);
    }
    int ans = Max(dp[numsSize - 1][0], dp[numsSize - 1][1]);
    Free(dp, numsSize);
    return ans;
}

```