思路同其他

```
var nextPermutation = function(nums) {
    let idx = nums.length - 2;
    while (idx >= 0 && nums[idx] >= nums[idx+1]) {
        idx--;
    }
    if (idx >= 0) {
        let i = idx+1, second = idx + 1;
        while (i < nums.length) {
            if (nums[i] < nums[second] && nums[i] > nums[idx]) second = i;
            i++;
        }
        [nums[idx], nums[second]] = [nums[second], nums[idx]];
        const re = nums.slice(idx+1).sort((a, b) => a - b);
        nums.splice(idx+1, re.length, ...re);
    } else {
        nums.reverse();
    }
};
```
