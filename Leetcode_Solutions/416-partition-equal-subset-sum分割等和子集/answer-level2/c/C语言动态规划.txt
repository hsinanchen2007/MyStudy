### 解题思路
重点就是状态转移矩阵，概念别的题解讲的已经很好了，重点在于第二个判断条件：dp[i - 1][j - nums[i - 1]]，（我这里的行数定义的多一行），这行的意义简单来说就是要考察：
假设目标数字减去当前数字后形成一个局部目标数字，而截止到当前数字前的那些数字能不能凑成这个局部目标数字，dp[i - 1][j - nums[i - 1]]这个位置上的数字就是结果，而初始值dp[0][0]为true是肯定的，注意判断边界即可

### 代码

```c
bool canPartition(int* nums, int numsSize){
    int i, j, target;
    // 统计一下所有数字之和，这个值的一般就是目标值，当然如果和为奇数肯定不行，要返回false
    int sum = 0;
    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (sum % 2 != 0) {
        return false;
    }
    target = sum / 2;
    // 为dp申请内存, 都初始化为false,然后第一列为true
    bool **dp = (bool **)malloc(sizeof(bool *) * (numsSize + 1));
    for (i = 0; i < numsSize + 1; i++) {
        dp[i] = (bool *)malloc(sizeof(bool) * (target + 1));
        memset(dp[i], false, sizeof(bool) * (target + 1));
        dp[i][0] = true;
    }
    // 从do[1][1]开始遍历数组，如果dp[i - 1][j]为true的话，那么dp[i][j]肯定为true，这说明
    // 已经有组合能够达到局部目标值了，再增加数字也不会改变结果，dp[i - 1][j - nums[i - 1]]
    // 如解题思路中说的，考察的是如果不算当前数字，之前的数字能否凑出来之前的局部目标值。
    for (i = 1; i < numsSize + 1; i++) {
        for (j = 1; j < target + 1; j++) {
            if (dp[i - 1][j] == true || (j - nums[i - 1] >= 0 && dp[i - 1][j - nums[i - 1]] == true)) {
                dp[i][j] = true;
            }
        }
    }
    // 最后只需要返回最后一行最后一列的值即可
    return dp[numsSize][target];
}
```