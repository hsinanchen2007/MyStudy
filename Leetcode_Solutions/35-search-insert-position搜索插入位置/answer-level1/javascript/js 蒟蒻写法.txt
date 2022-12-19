渣渣写法了

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    
    
    const isLargeNumber = (element) => element == target;

    const bxt = (element) => element > target;

    if(nums.includes(target)) {
        return nums.findIndex(isLargeNumber)
    }

    if(target>nums[nums.length-1]) {
        return nums.length
    }

    return nums.findIndex(bxt)

};
```