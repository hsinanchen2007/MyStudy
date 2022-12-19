![image.png](https://pic.leetcode-cn.com/26818b6a4baedd6e3da5bd1d8b2ce68f582bd7ef33970469049fb1b9e7fd13b9-image.png)

dp[i]节点保留两个参数
sum: 表示nums[sIndex]~nums[i]的和
sIndex: 表示nums[sIndex]~nums[i]的和刚好满足>=s
```

struct MyNode{
    int sIndex;
    int sum;
};
int minSubArrayLen(int s, int* nums, int numsSize)
{
    if(nums == NULL || numsSize == 0){
        return 0;
    }
    struct MyNode dp[numsSize];
    dp[0].sum = nums[0];
    dp[0].sIndex = 0;

    int tmpSum = 0;
    int ret = INT32_MAX;
    if(dp[0].sum >=s){
        ret = 1;
    }

    for(int i=1; i<numsSize; i++){
        tmpSum = dp[i-1].sum + nums[i];
        if(tmpSum >= s){
            for(int j=dp[i-1].sIndex; j<=i; j++){
                dp[i].sIndex = j;
                dp[i].sum = tmpSum;
                tmpSum -= nums[j];
                if(tmpSum < s){
                    break;
                }
            }
        }else{
            dp[i].sIndex = 0;
            dp[i].sum = tmpSum;
        }
        if(dp[i].sum >=s && i-dp[i].sIndex + 1 < ret){
            ret = i-dp[i].sIndex + 1;
        }
    }
    
    return ret==INT32_MAX?0:ret;
}
```



