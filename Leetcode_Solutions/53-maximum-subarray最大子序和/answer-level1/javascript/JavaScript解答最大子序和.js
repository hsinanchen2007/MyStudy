```
  var maxSubArray = function(nums) {
    if(!nums.length) return -1;
    let maxArray = [nums[0]]
    let max = nums[0]
    for(let j=1;j<nums.length;j++){
      maxArray.push(nums[j])
      let newSum = nums[j] + nums[j-1]
      if(nums[j]> nums[j-1] && nums[j-1] < 0){
        maxArray =[]
        maxArray[0] = nums[j]
      } else {
        nums[j] = newSum
      }
      if(nums[j]>max){
        max = nums[j]
      }
    }
     return max
  }
```
