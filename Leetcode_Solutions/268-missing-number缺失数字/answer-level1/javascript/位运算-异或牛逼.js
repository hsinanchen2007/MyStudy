```
var missingNumber = function(nums) {
    let res = nums.length
    for(let i=0; i<nums.length; i++) {
        res ^= i ^ nums[i] // 0 3 1 0 2 1
    }
    return res ^ 0
};
```
