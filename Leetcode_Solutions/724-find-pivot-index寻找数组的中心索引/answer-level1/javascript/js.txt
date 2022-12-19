### 解题思路
用left_ind标记中心索引位置，每次加1，比较两边总和

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function (nums) {
  let len = nums.length
  let left_ind = 0
  let left_sum = 0
  let right_sum = 0
  for (let i = 1; i < len; i++) {
    right_sum += nums[i]
  }
  while (left_ind < len) {
    if (left_sum !== right_sum) {
      left_sum += nums[left_ind]
      right_sum -= nums[left_ind+1]
      left_ind++
    } else {
      return left_ind
    }
  }
  return -1
}
```