```
var searchInsert = function(nums, target) {
    if(nums.indexOf(target)>-1) return nums.indexOf(target)
    for(let i =0;i<nums.length;i++){
          if(nums[i]>target){
            return i
            break
        }
    }
	 return nums.length       
};
```
