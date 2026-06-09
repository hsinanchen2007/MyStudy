
1. 在数组中找两个数等于当前数，我们定义左指针l=0,右指针r = nums.length -1
2. 在两个数中取值，当左边的值nums[l] + nums[r] 比给定的target大时，r--，同理小时l++
3. 当正好等于时就是我们求的结果

```
var twoSum = function(nums, target) {
      let l = 0
      let r = nums.length -1 
      while(l<r){
            if(nums[r]+nums[l]>target){
                r--
            } else if(nums[r]+nums[l]===target){
                return [nums[l],nums[r]]
            } else {
                l++
            }
      }
};
```
