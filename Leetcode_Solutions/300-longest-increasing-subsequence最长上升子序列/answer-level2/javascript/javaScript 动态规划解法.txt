```javascript []
var lengthOfLIS = function(nums) {
    if(nums.length == 0) return 0;
    if(nums.length == 1) return 1;
    let dp = [0, 1];
    for(let i = 2; i <= nums.length; i ++){
        let max = [];
        for(let j = 0; j < i -1; j ++){
            max.push(nums[i - 1] > nums[j]?(dp[j + 1] +1): 1);
        }
        dp[i] =Math.max.apply(null, max);
    }
    return Math.max.apply(null, dp);
};
```
