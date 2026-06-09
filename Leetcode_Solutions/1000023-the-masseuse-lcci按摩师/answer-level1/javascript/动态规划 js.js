```
/**
 * @param {number[]} nums
 * @return {number}
 * dp[n] = nums[n]+max(dp[n-2],dp[n-3])
 * dp[n] 代表当选n时的最优结果
 * 
 */
var massage = function(nums) {
    let max = 0;
    let dp = [];
    for(let n = 0;n<nums.length;n++){
        if(n>2){
            dp[n] = nums[n]+Math.max(dp[n-2],dp[n-3]);
        }else if(n==0){
            dp[n] = nums[0];
        }else if(n == 1){
            dp[n] = nums[1];
        }else{
            dp[n] = nums[0] + nums[2];
        }
        max = Math.max(max,dp[n]);
    }
    return max;
};
```
