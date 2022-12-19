var moveZeroes = function(nums) {
  let count = 0
  while(nums.indexOf(0) !== -1){
    nums.splice(nums.indexOf(0),1)
    count++
  }
  while(count) {
    nums.push(0)
    count--
  }
};