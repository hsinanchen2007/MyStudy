var singleNumber = function(nums) {
  return nums.reduce((v1, v2) => v1 ^ v2)
};