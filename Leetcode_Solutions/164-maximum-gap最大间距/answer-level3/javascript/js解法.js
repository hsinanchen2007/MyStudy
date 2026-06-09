```
var maximumGap = function(nums) {
    //nums = [3,6,9,1];
    if(nums.length === 1){
      return 0;
    } else if(nums.length === 2){
      return Math.abs(nums[1]-nums[0])
    } else {
      nums.sort((a,b)=>{return a-b});
      // nums = [1,3,6,9];
      var max = 0;
      for(let i = 1;i<nums.length;i++){
        var gap = nums[i] - nums[i-1];
        max = gap > max ? gap : max
      }
    }
    return max
};
```