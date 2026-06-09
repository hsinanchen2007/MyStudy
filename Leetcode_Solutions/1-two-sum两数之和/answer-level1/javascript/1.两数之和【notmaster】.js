
## 思路
两层循环：
已知目标值 target，外层循环依次计算 target 和数组中对应位置的数值的差值 diff，接下来就是再用一个循环判断 diff 是否存在于数组中，如果存在，就返回数组 [外层循环计算, 内层循环计算]。
此方法的内层循环计数应该从外层计算 +1 开始，从而排除不必要的判断。

## 代码

```javascript
var twoSum = function (nums, target) {
    for (var i = 0; i < nums.length; i++) {
        var diff = target - nums[i];
        for (var j = i + 1; j < nums.length; j++) {
            if (diff == nums[j]) {
                return [i, j]
            }
        }
    }
};
```