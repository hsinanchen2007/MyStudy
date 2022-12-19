可以使用动态规划来实现。
本方法为使用空间换时间。
用dp[i]（是一个哈希数表）记录遍历到nums[i]之后可以得到的所有可能sum值以及每个值对应的方法数。

具体的实现过程：
1、初始化dp[i]为一个空表
2、遍历dp[i-1]表中的每一个key值，分别对其进行key+nums[i]和key-nums[i]操作，记为base
3、若dp[i]表中已经有base，则dp[i][base]+=dp[i-1][key]，即加上dp[i-1]中key值的方法数。
4、若dp[i]表中没有base，则dp[i][base]=dp[i-1][key]，即就等于key值的方法数。
5、将dp[i-1]中的所有key遍历完成后，同时完成dp[i]的建立，令i++，重复以上步骤，知道遍历完nums数组的最后一个数

最后输出dp[nums.length][S] ? dp[nums.length][S] : 0;
代码如下：
```javascript
var findTargetSumWays = function(nums, S) {
    if(nums===null||nums.length===0)
        return 0;
    var dp = [];
    dp[0] = {};
    if(nums[0]===0){
        dp[0][0] = 2;
    } else {
        dp[0][nums[0]] = 1;
        dp[0][-nums[0]] = 1;
    }
    for(var i=1; i<nums.length; i++) {
        dp[i] = {};
        for(key in dp[i-1]) {
            let base = parseInt(key);
            let target = base+nums[i];
            if(!dp[i][target]) {
                dp[i][target] = dp[i-1][base];
            }else if(dp[i][target]){
                dp[i][target] += dp[i-1][base];
            }
            target = base-nums[i];
            if(!dp[i][target]) {
                dp[i][target] = dp[i-1][base];
            }else if(dp[i][target]){
                dp[i][target] += dp[i-1][base];
            }
        }
    }
    return dp[nums.length-1][S]?dp[nums.length-1][S]:0;
};