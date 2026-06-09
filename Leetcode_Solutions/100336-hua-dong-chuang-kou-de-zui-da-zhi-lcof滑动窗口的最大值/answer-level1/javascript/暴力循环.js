### 解题思路


### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function(nums, k) {
  let result = []
  if(!nums.length) return []
  for(let i= 0;i+k<=nums.length;i++) {
      let arr = nums.slice(i,i+k)
      result.push(Math.max.apply(Math,arr))
  }
  return result
};
```