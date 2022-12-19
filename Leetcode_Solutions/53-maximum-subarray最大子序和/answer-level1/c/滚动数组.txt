### 解释
    我太难了，菜的真实，虽然我第一次写leetcode，但居然交了十几次，最开始我用二维数组dp[i][j];
    来表示从第i个到第j个数的总和，先初始化dp[0][0]到dp[0][n];就是普通的加和，在用dp[i][j] = dp[i -     1][j] - nums[i - 1];来迭代求和，其实就是比如dp[i][j]从第i个到第j个减去最后一个数来表示从第i+1个到第j个数，结果被倒数第2个示例卡了，开的数组太大，然后更换滚动数组，然后各种错，最后才对了，我太难了
### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int dp[numsSize];
    int dpp[numsSize];
    int res = nums[0];
    memset(dp,INT_MIN,sizeof(dp));
    dp[0] = nums[0];
    for(int i = 1; i < numsSize; i ++){
        dp[i] = dp[i - 1] + nums[i];
        dpp[i] = dp[i];
        if(res < dp[i])res = dp[i];
        //printf("%d ",dp[i]);
    }
    //printf("\n");
    
    for(int i = 1; i < numsSize; i ++){
        for(int j = i; j < numsSize; j ++){
            if(i == j) dp[i] = nums[i];
            if(i != j) dp[j] = dpp[j] - nums[i - 1];
            if(res < dp[j])res = dp[j];
        }
        memcpy(dpp,dp,sizeof(dp));
        //for(int i = 0; i < numsSize; i ++)printf("%d ",dp[i]);
        //printf("\n");
    }
    return res;
}
```