思路：
基本思路与[这道题](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/solution/javascriptjie-fa-by-azleal/)一致。只不过多了一个最多次数的条件
```
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let slowPointer = 1
    let count = 1
    let processedNum = nums[0]
    for(let fastPointer = 1; fastPointer < nums.length; fastPointer++){
        if(nums[fastPointer] == processedNum && count < 2){
            //重复出现，更新count即可
            nums[slowPointer++] = nums[fastPointer]
            count++
        }else if(nums[fastPointer] != processedNum){
            //出现新数字，更新count和processedNum
           nums[slowPointer++] = nums[fastPointer]
           processedNum = nums[fastPointer]
           count=1
        }
    }
    return slowPointer
};
```