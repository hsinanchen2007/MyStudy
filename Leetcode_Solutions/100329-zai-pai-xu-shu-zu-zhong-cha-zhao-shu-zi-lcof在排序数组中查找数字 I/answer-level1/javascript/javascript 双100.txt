```
var search = function(nums, target) {
    let left = 0, right = nums.length -1;
    let mid = parseInt((left + right)/2)
    let index = -1;
    while(left <= right){
        if(nums[mid] == target){
            index = mid;
            break;
        }
        if(nums[mid] > target){
            right = mid-1;
            mid = parseInt((left + right) / 2)
        }
        if(nums[mid] < target){
            left = mid+1;
            mid = parseInt((left + right) / 2)
        }
    }
    if(index == -1) return 0;
    let i = index, j = index;
    while(i >= 0 && nums[i] == target) i--
    while(j < nums.length && nums[j] == target) j++
    return j-i-1

};
```
