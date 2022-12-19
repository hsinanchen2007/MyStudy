`内联代码````
var searchInsert = function(nums, target) {
    for(let i = 0; i<nums.length; i++){
       if(target == nums[i]){
           return i
       }else if(target > nums[i] && target <nums[i+1]){
           return i+1
           
       }else{
           if(target > nums[nums.length-1]){
               return nums.length
           }else if(target < nums[0]){
               return 0
           }
           //return nums.indexOf(target)
       }
    }
};
```
