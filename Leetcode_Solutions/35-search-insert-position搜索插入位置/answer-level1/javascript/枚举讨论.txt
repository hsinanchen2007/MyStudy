```
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    if (nums.includes(target)) {
        for(var i=0; i<nums.length; i++){
            if(nums[i] === target){
                return i
            }
        }
    }else{
        for(var i=0; i<nums.length; i++){
            // 答案在末
            if(nums[nums.length-1]<target){
                return nums.length
            }
            // 答案在中
            if(nums[i] < target && nums[i+1] > target){
                return i+1
            }
            // 答案在首
            if(nums[0]>target){
                return 0
            }
        }        
    }    
};
```
- 执行用时 :68 ms, 在所有 javascript 提交中击败了77.73%的用户
- 内存消耗 :33.7 MB, 在所有 javascript 提交中击败了73.57%的用户
- 按照提议分别讨论集中情况
