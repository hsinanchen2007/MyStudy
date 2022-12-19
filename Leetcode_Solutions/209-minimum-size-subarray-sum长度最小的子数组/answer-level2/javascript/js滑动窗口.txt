```
var minSubArrayLen = function(s, nums) {
    let l = 0, r = -1, len = nums.length, res = len + 1, sum = 0
    while(l < len) {
        sum < s && (r + 1 < len) ? sum += nums[++r] : sum -= nums[l++]
        if (sum >= s) 
            res = Math.min(res, (r - l + 1))
        
    }
    return res === (len + 1) ? 0 : res
};
```
