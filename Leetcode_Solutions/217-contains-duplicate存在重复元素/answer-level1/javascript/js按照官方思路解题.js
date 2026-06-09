1.暴力法
```
var containsDuplicate = function(nums) {
    if(nums.length <= 1){
        return false;
    }
    for(let i=0;i<nums.length;i++){
        for(let j=0;j<nums.length&&j!=i;j++){
           if(nums[i] === nums[j]){
               return true;
           } 
        } 
    }
    return false;
};
```
2.排序法
```
var containsDuplicate = function(nums) {
    if(nums.length <= 1){
        return false;
    }
    nums = nums.sort();
    for(let i=0;i<nums.length;i++){
        if((i+1)<nums.length && nums[i] === nums[i+1]){
            return true;
        }
    }
    return false;
};
```