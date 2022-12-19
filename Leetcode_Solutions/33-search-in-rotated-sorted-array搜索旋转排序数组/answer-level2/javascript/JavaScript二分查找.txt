```
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    if(!nums || nums.length === 0) return -1;
    var start = 0;
    var end = nums.length-1;
    var mid;
    while(start <= end){
        mid = start + ((end - start)>>>1);
        if (nums[mid] === target) {
            return mid;
        }
        //左半部分升序
        if(nums[start] <= nums[mid]){
            if(target >= nums[start] && target < nums[mid]){ //target在左半部分
                end = mid - 1;
            }else{ //target在左半部分
                start = mid + 1;
            }
        }else{//右半部分升序
            if(target <= nums[end] && target > nums[mid]){//target在右半部分
                start = mid + 1;
            }else{//target在左半部分
                end = mid - 1;
            }
        }
    }
    return -1;
};
```
