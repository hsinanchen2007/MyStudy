### 解题思路
动态规划问题 
递推方程为dp[i]=max(dp[i-1],dp[i-2]+num[i])
### 代码

```c
int massage(int* nums, int numsSize){
    int a=0,b=0,i=0;
    for(i;i<numsSize;i++)
    {
        int c = b>(a+nums[i])?b:(a+nums[i]);
        a=b;
        b=c;
    }
    return b;

}
```