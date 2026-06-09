### 解题思路
动态规划，dp[i]记录每一个状态，dp[i]=dp[i-1]+nums[i],,dp[i] = nums[i]

### 代码

```javascript
/**
 * 动态规划，dp[i]记录每一个状态，dp[i]=dp[i-1]+nums[i],,dp[i] = nums[i]
 */
var maxSubArray = function(nums) {
    var dp = [];
    var res=nums[0];
    dp[0] = nums[0]
    for(var i=1; i < nums.length; i++){
        // if(dp[i-1] < 0){
        //     dp[i] =nums[i]
        // }else{
        //     dp[i] = dp[i-1] + nums[i]
        // }
        dp[i] = (dp[i-1] < 0) ? nums[i] : dp[i-1] + nums[i]

        console.log(dp[i])
    }
    for(var i=1; i <nums.length; i++){
        res = Math.max(res,dp[i])
    }
    return res;
};















```