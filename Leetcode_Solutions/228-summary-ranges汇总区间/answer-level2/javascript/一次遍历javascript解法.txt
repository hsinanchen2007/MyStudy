### 解题思路

大家好，我是 17

这题应该是简单题，记录上一个数，当前数如果是上一个数加1，就是本区间的，否则新开一个区间

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function (nums) {
  let cur = nums[0] - 1
  let result = []
  let item = []
  for (let n of nums) {
    if (++cur === n) {
      item.push(n)
    }
    else {
      result.push(item)
      item = [n]
      cur = n
    }
  }
  if (item.length > 0) {
    result.push(item)
  }
  return result.map(item => { 
    if (item.length > 1) { 
      return `${item[0]}->${item[item.length-1]}`
    }
    else {
      return `${item}`
    }
  })

};
```