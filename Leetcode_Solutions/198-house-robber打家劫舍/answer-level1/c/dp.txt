### 解题思路
此处撰写解题思路

### 代码

```c
int max(int a,int b){
    return a > b ? a : b;
}
int rob(int* nums, int numsSize){
    if(nums == NULL ||numsSize == 0) return 0;
    int *dp = (int *)calloc(numsSize, sizeof(int));
    dp[numsSize - 1] = nums[numsSize - 1];
    for(int i = numsSize - 2; i >= 0; i--){
        for(int j = i; j <= numsSize - 1; j++){
            dp[i] = max(dp[i], nums[j] + (j + 2 < numsSize ? dp[j+2] : 0));
        }
    }
    return dp[0];
}
```