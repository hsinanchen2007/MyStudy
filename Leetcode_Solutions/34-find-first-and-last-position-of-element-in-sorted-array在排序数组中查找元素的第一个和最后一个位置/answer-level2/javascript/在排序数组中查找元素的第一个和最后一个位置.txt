```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    var left = 0
    var right = nums.length - 1
    while(left <= right){
        var middleIndex = Math.floor((right-left)/2) + left
        var temp = nums[middleIndex]
        if(target > temp){
            left = middleIndex + 1  
        }else if(target < temp){
            right = middleIndex - 1
        }else if(target === temp){
            if(nums[left] !== target){
                left = left + 1
            } else if(nums[right] !== target){
                right = right - 1    
            } else {
                return [left,right]
            }
        }
    }
    return [-1,-1]
};
```
