### 解题思路
递归

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
  var i = 0;
  var mode = undefined;
  function recursive(nums) {
    if (!nums.length) return
    if (nums[i] !== mode) {
      mode = nums[i]
      i++
      recursive(nums)
      return
    }
    nums.splice(i, 1)
    // console.log(i, nums)
    if (i >= nums.length) {
      return
    }
    recursive(nums)
  }
  recursive(nums)
}
```