思路：
双指针解法。快指针遍历数组，当遇到满足条件的项则更新慢指针所在项，并更新慢指针。

```
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let slowPointer = 1
    //已经处理过的数字
    let processedNum = nums[0]
    for(let fastPointer = 1; fastPointer < nums.length; fastPointer++){
        if(nums[fastPointer] != processedNum){
           nums[slowPointer++] = nums[fastPointer]
           processedNum = nums[fastPointer]
        }
    }
    return slowPointer
};
```