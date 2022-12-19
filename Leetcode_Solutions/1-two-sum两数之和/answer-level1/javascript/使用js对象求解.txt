使用对象hash结构，边循环边查找
```
var twoSum = function(nums, target) {
  const obj = new Object()
  for (let i = 0; i < nums.length; i ++) {
    const otherIndex = obj[target - nums[i]]
    if (otherIndex !== undefined) return [otherIndex, i]
    obj[nums[i]] = i
  }
};
```
