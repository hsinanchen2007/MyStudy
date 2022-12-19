```
var findLHS = function(nums) {
    let obj = {};
    let max = 0;
    for (let i = 0; i < nums.length; i++) {
        if(obj[nums[i]] == undefined) {
            obj[nums[i]] = 1;
        } else {
            obj[nums[i]]++;
        }
        if (obj[nums[i] + 1] !== undefined) {
            max = Math.max(max, obj[nums[i]] + obj[nums[i] + 1])
        }
        if (obj[nums[i] - 1] !== undefined)
            max = Math.max(max, obj[nums[i]] + obj[nums[i] - 1])
    }
    return max
};
```
