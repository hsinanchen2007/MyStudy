1. 常规 dp 解法, 第 i 天的最长预约时间
dp[i] = Math.max(dp[i-1], dp[i-2] + nums[i])
```
var massage = function (nums) {
    var len = nums.length;
    if (len === 0) return 0;
    if (len === 1) return nums[0];
    var dp = [];
    dp[0] = nums[0];
    dp[1] = Math.max(nums[0], nums[1]);
    for (var i = 2; i < nums.length; i++) {
        dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[len - 1];
};
```
2. dp 空间优化
```
var massage = function (nums) {
    var a = 0 ;
    var b = 0;
    for(var i = 0;i < nums.length; i++){
        var c = Math.max(b, a + nums[i]);
        a = b;
        b = c;
    }
    return b;
}
```

