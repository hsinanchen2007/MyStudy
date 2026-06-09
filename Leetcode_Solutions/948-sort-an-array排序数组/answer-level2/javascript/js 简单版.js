```
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    if(nums.length === 0) {
        return []
    }

    return nums.sort((a,b) => a-b)
};
```
