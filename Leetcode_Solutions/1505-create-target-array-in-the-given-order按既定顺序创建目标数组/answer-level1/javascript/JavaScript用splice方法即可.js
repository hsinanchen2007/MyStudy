```
/**
 * @param {number[]} nums
 * @param {number[]} index
 * @return {number[]}
 */
var createTargetArray = function(nums, index) {
    var i;
    var target=[];
    for(i=0;i<nums.length;i++){
         target.splice(index[i], 0, nums[i]);
    }
 return target;
};
```

