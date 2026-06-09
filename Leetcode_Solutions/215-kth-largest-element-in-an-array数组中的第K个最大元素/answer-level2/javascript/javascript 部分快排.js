```
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var helper = function(nums, i, j, k){
  if(i >= j) return nums[i]
  let flag = nums[i]
  let middle = i
  for(let q=i+1; q<=j; q++){
    if(nums[q] < flag){
      let temp = nums[middle+1]
      nums[middle+1] = nums[q]
      nums[q] = temp
      middle++
    }
  }
  nums[i] = nums[middle]
  nums[middle] = flag
  if((nums.length-k) < middle){
    return helper(nums, i, middle-1, k)
  }else if((nums.length-k) > middle){
    return helper(nums, middle+1, j, k)
  }else {
    return nums[middle]
  }
}

var findKthLargest = function(nums, k) {
  return helper(nums, 0, nums.length-1, k)
};
```
