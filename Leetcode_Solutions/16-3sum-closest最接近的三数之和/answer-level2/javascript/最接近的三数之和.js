```js
var threeSumClosest = function(nums, target) {
    nums.sort((a, b) => a - b)
    let len = nums.length;
    let closestNum = nums[0] + nums[1] + nums[2];
    for (let i = 0; i < len - 2; i++) {
        let L = i + 1;
        let R = len - 1;
        while (L < R) {
            const sum = nums[i] + nums[L] + nums[R];
            if (Math.abs(sum - target) < Math.abs(closestNum - target)) {
                closestNum = sum
            }
            if (sum > target) {
                R--
            } else if (sum < target) {
                L++
            } else {
                // 如果已经等于target的话, 肯定是最接近的
                return target
            }
        }
    }
    return closestNum
};
```
