### 解题思路
DP初级题，一维动态规划，DP数组用来存放最优解

### 代码

```c
int max (int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int massage(int* nums, int numsSize){

    int *dp;
    int i;
    int tmpA, tmpB;

    dp = (int *)malloc(sizeof(int) * 10000);
    memset(dp, 0, sizeof(int) * 10000);

    tmpA = 0;
    tmpB = 0;

    if (numsSize <= 0)
        return 0;
    else
    {
        for (i = 0; i < numsSize; i ++)
        {
            if (i == 0)
            {
                dp[i] = nums[0];
            }
            else if (i == 1)
            {
                dp[i] = max(nums[0], nums[1]);
            }
            else
            {
                tmpA = dp[i - 2] + nums[i];
                tmpB = dp[i - 1];
                dp[i] = max(tmpA, tmpB);
            }
        }
    }

    return dp[numsSize-1];

}
```