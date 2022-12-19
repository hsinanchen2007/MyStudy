本题和198. 打家劫舍 一模一样，就是换了身衣服

```
int max(int a,int b){
    return a>b?a:b;
}

int massage(int* nums, int numsSize){
    /*
        打家劫舍问题
        1.动态规划
        n轮最长时间 = max {n-1轮最长时间，n-2轮最长时间+本次时间};  O(n);
    */

    int dp[10000] = {0};
    //memset(dp, 0, sizeof(int));

    if (!nums || numsSize <= 0){
        return 0;
    }

    //注意越界风险
    if (numsSize < 2){
        return nums[0];
    }

    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);


    for (int i = 2; i < numsSize; i++){
        dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
    }

    return dp[numsSize - 1];
}
```
