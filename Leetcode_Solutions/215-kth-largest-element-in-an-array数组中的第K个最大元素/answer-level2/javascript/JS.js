```
var findKthLargest = function(nums, k) {
  nums.sort((a,b)=>{return b-a});
  return nums[k-1]
};
```