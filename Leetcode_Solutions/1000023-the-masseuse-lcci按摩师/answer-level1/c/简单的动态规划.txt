### 解题思路
1.有效数字长度的判断，如果是只有0,1,2个数字的单独判断;
2.更新有效值dp[i]的值，需要注意的是，dp[i-1]也需要同步更新；
3，返回最后的结果。
我没释放内存，这个不写了

### 代码

```c
int max(int a, int b) {
    return a > b ? a: b;
}
int massage(int* nums, int numsSize){
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    int *dp = (int *)malloc(sizeof(int) * numsSize);
    int i;
    if (numsSize <3)
        return nums[0] > nums[1] ? nums[0]: nums[1];
    
    dp[0] = nums[0];
    dp[1] = nums[1];

    for (i = 2; i < numsSize; i++) {
        dp[i] = max(dp[i-2] + nums[i],dp[i-1]);
        dp[i - 1] = max(dp[i-2],dp[i - 1]);
    }

    return dp[numsSize -1];
}
```