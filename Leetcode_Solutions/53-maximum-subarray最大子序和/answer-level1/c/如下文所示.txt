### 解题思路
常规的dp操作，dp[i]是到i为止最大的连续子序列和，那么要想求dp[i]就必须要求得dp[i-1];
而这个特征方程就是：如果dp[i-1] + a[i] > a[i]:dp[i] = dp[i-1] + a[i];否则dp[i]就等于a[i]
最后选出最大的即可
### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int i;
    int dp[100010] = {0};
    dp[0] = nums[0];
    int max = dp[0];
    for(i = 1; i < numsSize; i++){
        if(dp[i-1] + nums[i] >= nums[i]){
            dp[i] = dp[i-1] + nums[i];
        }else{
            dp[i] = nums[i];
        }
        if(max < dp[i]){
            max = dp[i];
        }
    }
    return max;
}
```