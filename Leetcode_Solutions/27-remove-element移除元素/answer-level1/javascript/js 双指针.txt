```
var removeElement = function(nums, val) {
    if(nums.length === 0)
        return 0;
    if(nums.length === 1 && nums[0] === val)
        return 0;
        if(nums.length === 1 && nums[0] !== val)
        return 1;
    let left = 0;
    for(let right = 0; right < nums.length; right++){
        if(nums[right] !== val){
            nums[left] = nums[right];
            left ++;
        }
    }
    return left;
};
```