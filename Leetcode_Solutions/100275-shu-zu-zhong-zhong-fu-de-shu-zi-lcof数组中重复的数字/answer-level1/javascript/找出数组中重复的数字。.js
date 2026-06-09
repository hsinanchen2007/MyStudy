### 解题思路
  利用数组的key唯一性，将原始数组的value当做新数组的key，挑选出重复的数字。感觉此题要求的输出有点问题吧，重复的数字可能会有很多个[滑稽]

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
  let onceNum = []
  let repeatNum = []
  for (let i = 0; i < nums.length; i++) {
    if (onceNum[nums[i]]) {
      repeatNum.push(nums[i])
    }
    onceNum[nums[i]] = true
  }
  return repeatNum[0] | null
};
```