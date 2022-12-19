```
var moveZeroes = function(nums) {
    for(let i= 0; i< nums.length; i++) {
        if (nums[i] === 0) {
            nums.push(nums.splice(i, 1));
            i--
        } 
    }
};
```
