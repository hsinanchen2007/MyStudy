首先将lower, upper加入首尾
求区间

```javascript
var findMissingRanges = function (nums, lower, upper) {
    let ans = []
    nums.unshift(lower - 1)
    nums.push(upper + 1)
    for (let i = 1; i < nums.length; i++) {
        let low = Math.max(nums[i - 1] + 1, lower)
        let up = Math.min(upper, nums[i] - 1)
        if (low == up) ans.push('' + low)
        else if (low < up) ans.push(low + '->' + up)
    }
    return ans;
};
```

![163.png](https://pic.leetcode-cn.com/6d826fdf6793221828be907501b24ef5ec5a024a0f53c255114e459a44671a18-163.png)

