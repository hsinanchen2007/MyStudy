```
var sortArray = function(nums) {
    if (nums.length < 2) {
        return nums;
    }
    let mid = nums[0], left = [], right = [], middle = [];
    for (let i = 0, len = nums.length; i < len; i++) {
        if (nums[i] < mid) {
            left.push(nums[i])
        } else if (nums[i] == mid) {
            middle.push(nums[i])
        } else if (nums[i] > mid) {
            right.push(nums[i])
        }
    }
    return sortArray(left).concat(middle, sortArray(right))
};
```

中间这段其实可以再优化，内存占用有些大了
