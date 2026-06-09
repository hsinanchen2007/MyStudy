### 
首先需要描述状态，用dp[i]表示以nums[i]结尾的最大连续和
状态方程为：
1、如果dp[i-1]<0,则dp[i]=nums[i]（连续和的前面在加一个负数，就是累赘，也可以这么理解，这个连续和的第一个数值一定大于0）
2、如果dp[i-1]>0，则dp[i]=dp[i-1]+nums[i]。

### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int dp[numsSize];
    dp[0]=nums[0];
    int i;
    for(i=1;i<numsSize;i++){
        if(dp[i-1]<0)
            dp[i]=nums[i];
        else
            dp[i]=dp[i-1]+nums[i];
    }
    int max=dp[0];
    for(i=1;i<numsSize;i++){
        max=max>dp[i]?max:dp[i];
    }
    return max;
}
```