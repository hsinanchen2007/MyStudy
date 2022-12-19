### 解题思路
时间O(n),空间O(1).    动态规划，dp[k]=max(dp[k-2]+nums[k],dp[k-1])

### 代码

```c

int rob(int* nums, int numsSize){
    int dp1=0,dp2=0,result=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]+dp1>dp2){
            result = nums[i]+dp1;
        }
            dp1 = dp2;
            dp2 = result;
    }
    return  result;
}
```