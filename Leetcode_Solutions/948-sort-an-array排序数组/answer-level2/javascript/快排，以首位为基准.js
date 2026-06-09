```
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var helper = function(nums, i, j){
  if(i >= j) return nums
  let flag = nums[i]
  let middle = i
  for(let k=i+1; k<=j; k++){
    if(nums[k] < flag){
      let temp = nums[middle+1]
      nums[middle+1] = nums[k]
      nums[k] = temp
      middle++
    }
  }
  nums[i] = nums[middle]
  nums[middle] = flag
  
  helper(nums, i, middle-1)
  helper(nums, middle+1, j)
  return nums
}

var sortArray = function(nums) {
  return helper(nums, 0, nums.length-1)
};
```
