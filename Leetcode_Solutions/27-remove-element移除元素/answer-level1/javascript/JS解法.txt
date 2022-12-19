```
var removeElement = function(nums, val) {
    for (let i = nums.length - 1, len = nums.length; i > -1; i--) {
        if (nums[i] == val) {
            nums.splice(i, 1)
        }
    }
    return nums.length
};
```

倒序遍历更优
