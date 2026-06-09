遍历数组，把数组的值设为对象的key，当下一个值已经是对象的key时，说明这个值就是重复的。
```
var findRepeatNumber = function (nums) {
    let ans = {};
    for (let i = 0; i < nums.length; i++) {
        if (ans[nums[i]] !== undefined) {
            return nums[i];
        } else {
            ans[nums[i]] = i;
        }
    }
};
```
