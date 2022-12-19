这里我们只需要循环整个数组，对每一个元素都用目标值相减得到另一个符合条件的值，然后使用indexOf查找是否在数组内且不是当前元素即可，可用当前元素index比较
```
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let length = nums.length
    for(let i = 0; i < nums.length; i++) {
        let item = nums[i]
        let other = target - item
        let index
        if((nums.indexOf(other) != -1 && nums.indexOf(other) != i)){
            index = nums.indexOf(other)
            return [i, index]
        }
    }
};
```