这个和我在node环境下结果不一样，不知道哪里错了
var removeElement = function(nums, val) {
  return nums.filter(x=>x!==val).length
};