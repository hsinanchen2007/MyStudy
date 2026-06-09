```js
var rotate = function(nums, k) {
    if (k == 0 || nums.length < 2) {
        return nums
    }
    var len = nums.length
    var n = k % len;
    for (let j = 0; j < n; j++) {
        nums.unshift(nums.pop())
    }
    return nums;
};
```