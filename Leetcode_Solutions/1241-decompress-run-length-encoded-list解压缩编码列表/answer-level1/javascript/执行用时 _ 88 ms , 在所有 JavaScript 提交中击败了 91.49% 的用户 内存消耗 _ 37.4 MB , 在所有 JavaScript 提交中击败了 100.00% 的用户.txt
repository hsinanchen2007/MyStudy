```
var decompressRLElist = function (nums) {
    let ans = []
    for (let i = 0; i < nums.length; i++) {
        if (i % 2 === 0) {
            while (nums[i]--) {
                ans.push(nums[i + 1])
            }

        }
    }
    return ans
};
```
