### 解题思路
核心逻辑：
1. 存在和相等，即部分子数组和为总数的1/2，即sum
2. 得状态 f(i,sum) = f(i-1,sum)||f(i-1, sum-nums[i]),其中f得解为，前i个元素中，存在和为sum得值，即出口当sum == 0 时，符合要求。


### 递归解题
```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {
    var sum = nums.reduce((a, b) => a + b) / 2;
    if (sum % 1 > 0) {
        return false;
    }

    function f(i, su) {
        // 如果传入值为0，即相等
        if (su == 0) {
            return true
        }
        // 如果传入值小于范围，则不相等
        if (su < 0 || i < 0) {
            return false
        }
        // 判断条件
        var sum1 = f(i - 1, su)
        var sum2 = f(i - 1, su - nums[i]);
        if (sum1 || sum2) {
            return true;
        }
        return false;
    }
    return f(nums.length - 1, sum);
};
```
### 非递归代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {
    var dp = []
    var sum = nums.reduce((a, b) => a + b) / 2;
    if (sum % 1 > 0) {
        return false;
    }


    for (var i = 0; i < nums.length; i++) {
        dp[i] = []
        for (var su = 0; su <= sum; su++) {
            if (su == 0) {
                dp[i][su] = true;
                continue;
            }
            var sum1, sum2
            var a = i - 1,
                b = su - nums[i]
            if (a < 0) {
                sum1 = sum2 = false;
            } else if (b < 0) {
                sum1 = dp[i - 1][su]
                sum2 = false
            } else {
                sum1 = dp[i - 1][su]
                sum2 = dp[i - 1][su - nums[i]]
            }
            dp[i][su] = sum1 || sum2;
        }
    }
    return !!dp[nums.length - 1][sum];
};
```