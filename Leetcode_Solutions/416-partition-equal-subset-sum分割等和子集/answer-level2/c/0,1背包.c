### 解题思路
此处撰写解题思路

### 代码

```c
bool canPartition(int* nums, int numsSize){

    int sum = 0;
    for(int i = 0;i < numsSize;i++)
    {
        sum += nums[i];
    }
    int target = 0;
    target = sum/2;

    if (sum %2 != 0)
    {
        return false;
    }
    
    int *dp = (int*)malloc(sizeof(int)*(target+1));
    memset(dp,0x0,sizeof(int)*(target+1));
    dp[0] = 1;

    for(int i  = 0;i < numsSize;i++)
    {
        for(int j =  target;j >= nums[i];j--)
        {
            dp[j] = dp[j] || dp[j-nums[i]];
        }
    }

    return dp[target];

}
```