### 解题思路
此处撰写解题思路

### 代码

```c
int massage(int* nums, int numsSize){
    int dp[3];
    int i;
    memset(dp,0,sizeof(dp));
    for(i=0;i<numsSize;i++)
    {
        dp[2]=nums[i];
        if(dp[1]>dp[0]+dp[2])
        dp[2]=dp[1];
        else
        dp[2]=dp[0]+dp[2];
        dp[0]=dp[1];
        dp[1]=dp[2];
    }
    return dp[1];
}
```