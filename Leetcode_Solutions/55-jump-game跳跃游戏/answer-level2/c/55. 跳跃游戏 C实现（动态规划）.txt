### 解题思路
此处撰写解题思路

### 代码

```c
bool canJump(int* nums, int numsSize){
    bool* dp = malloc(sizeof(bool) * numsSize);
    dp[numsSize - 1] = true;
    for (int i = numsSize - 2; i > -1; --i) {
        int idxLim = nums[i] + i;
        if (idxLim >= numsSize) {
            idxLim = numsSize - 1;
        }
        dp[i] = false;
        for (int j = idxLim; j > i; --j) {
            if (dp[j]) {
                dp[i] = true;
                break;
            }
        }
    }
    bool ret = dp[0];
    free(dp);
    return ret;
}
```