```js
var checkPossibility = function(nums) {
    let count = 0;
    if (nums[0] > nums[1]) {
        nums[0] = nums[1];
        count++
    }
    for (let i = 1; i < nums.length-1; i++) {
        let left = nums[i-1];
        let right = nums[i+1];
        if (nums[i] > nums[i+1]) {
            ++count;
            // 不用再向后看了
            if (count > 1) {
                return false
            }
            if (left > right) {
                nums[i+1] = nums[i]
            } else {
                nums[i] = left;
            }
        } 
    }
    return true
};
var nums = [3,4,2,3];
console.log(checkPossibility(nums));
```

