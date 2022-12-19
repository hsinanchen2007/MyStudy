```
var findLengthOfLCIS = function(nums) {
  let max = 0;
  let temp = 1;
  for (let i = 0; i < nums.length; i++) {
      if (nums[i+1] > nums[i]) {
          temp++;
      } else {
          max = Math.max(temp, max);
          temp = 1;
      }
  }
    return max
};
```
