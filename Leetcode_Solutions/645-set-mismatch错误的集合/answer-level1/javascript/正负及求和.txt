1. 遍历一次，把那个数对应的值置为负数
2. 下次遇到要置的数字为负数时， 这个数就是重复的
3. 统计数组的和（不包括重复的数字）
4. 丢失的数字为本来数字的和减去数组的和



```javascript
var findErrorNums = function(nums) {
  var res = []
  var len = nums.length
  var sum = 0
  for (var i = 0; i < len; i++) {
    if (nums[Math.abs(nums[i]) - 1] < 0) {
      res[0] = Math.abs(nums[i])
      continue
    }
    else nums[Math.abs(nums[i]) - 1] *= -1
    sum += Math.abs(nums[i])

  }
  res[1] = (len * (len + 1)) / 2 - sum
  return res
}

```
