
生成两个数组，然后对比两个数组的值，不一样，就是所求的值。


```javascript
const findRepeatNumber = function (nums) {
  let newNums = Array.from(new Set(nums))
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== newNums[i]) {
      return nums[i]
    }
  }
}
```