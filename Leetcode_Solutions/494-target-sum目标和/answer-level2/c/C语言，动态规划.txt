- 状态定义：dp[i][j]为前i+1个数字的和达到j的总方法数,dp[0][j]，为前1个数字达到和为j的总方法数
- 边界条件：
    1.由于每位数字可取正取负，假如和的范围为`[-1000,1000]`(题目给出和不超过1000),将其平移至[0,2000]，以方便处理，因为数组下标必须大于或等于0
    2.初始化为:
```
    dp[0][1000+nums[0]] = 1;
    dp[0][1000-nums[0]] += 1; //由于 nums[0] = 0时，dp[0][1000±0] = 2;

```
- 状态转移方程
    j-nums[i] >= 0时，dp[i][j] += dp[i-1][j-nums[i]];
    j+nums[i] < 2000时，dp[i][j] += dp[i-1][j+nums[i]];

代码如下：
```
int findTargetSumWays(int* nums, int numsSize, int S){
    int dp[numsSize+1][2001];
    memset(dp,0,sizeof(dp));
    dp[0][nums[0]+1000] = 1;
    dp[0][-nums[0]+1000] += 1; //当nums[0] = 0时
    for(int i=1;i<=numsSize;i++)
        for(int j=0;j<=2000;j++){
            if(j-nums[i]>=0)
                dp[i][j] += dp[i-1][j-nums[i]];
            if(j+nums[i]<=2000)
                dp[i][j] += dp[i-1][j+nums[i]];
        }
    return dp[numsSize-1][S+1000];
}

```
