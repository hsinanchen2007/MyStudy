```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function (nums) {
    var len = nums.length
    if(!len) return 0
    var dp = new Array(len).fill(1)
    for (var i = 0; i < len; i++) {
        var temp = nums[i]
        for (var j = 0; j < i; j++) {
            if (nums[j] < temp) {
                dp[i] = Math.max(dp[i], dp[j] + 1)
            }
        }
    }
    return Math.max.apply(Math, dp)
};
```
