### 解题思路
每一天的状态只有接或不接，定义一个数组dp[numssize][2]存放接和不接的最大时长值，第一天不接就是0，接就是nums[0],而后一天是否能接取决于前一天的状态，如果不接就是前一天的接或不接的最大值，如果接就必须是前一天不接的值加上nums[i]。

### 代码

```c
#define max(a,b) (a)>(b)?(a):(b)
int massage(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    int dp[numsSize][2];
    dp[0][0]=0;
    dp[0][1]=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        dp[i][1] = dp[i-1][0]+nums[i];
    }
    return max(dp[numsSize-1][0],dp[numsSize-1][1]);
}
```