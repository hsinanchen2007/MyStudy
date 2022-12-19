```
var search = function(nums, target) {
  let count=1;
  if(nums.indexOf(target)===-1){
    return 0
  }else{
    for(let i=nums.indexOf(target);i<nums.length;i++){
      if(nums[i]!==nums[i+1]){
        return count
      }else{
        count++
      }
    }
  }
};

```
