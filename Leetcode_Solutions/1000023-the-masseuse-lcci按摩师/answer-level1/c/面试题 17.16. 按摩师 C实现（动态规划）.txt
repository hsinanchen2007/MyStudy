### 解题思路
此处撰写解题思路

### 代码

```c
inline int MaxNum(int a, int b)
{
    return a > b ? a : b;
}

inline void FreeDpArr(int** dp, int numsSize)
{
    for (int i = 0; i < numsSize; i++) {
        free(dp[i]);
    }
    free(dp);
    return;
}

int massage(int* nums, int numsSize){
    if (!nums || numsSize <= 0) {
        return 0;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    int** dp = (int**)malloc(sizeof(int*) * numsSize);
    int mallocSize = sizeof(int) * 2;
    dp[0] = (int*)malloc(mallocSize);
    dp[0][0] = nums[0];
    dp[0][1] = 0;
    int pre;
    for (int i = 1; i < numsSize; i++) {
        dp[i] = (int*)malloc(mallocSize);
        pre = i - 1;
        dp[i][0] = dp[pre][1] + nums[i];
        dp[i][1] = MaxNum(dp[pre][0], dp[pre][1]);
    }
    int ans = MaxNum(dp[numsSize - 1][0], dp[numsSize - 1][1]);
    FreeDpArr(dp, numsSize);
    return ans;
}
```