### 解题思路
新手基础向：冒泡或者选择n次即可

### 代码

调库-笑

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
  return nums.sort((a, b) => b - a)[k - 1]
};
```

冒泡 k 次

```javascript
var findKthLargest = function(nums, k) {
  let len = nums.length - 1
  for (let i = len; i > len - k; i--) {
    for (let j = 0; j < i; j++) {
      if (nums[j] > nums[j + 1]) {
        const tmp = nums[j]
        nums[j] = nums[j + 1]
        nums[j + 1] = tmp
      }
    }
  }
  return nums[nums.length - k]
};
```

选择 k 次
```javascript
var findKthLargest = function(nums, k) {
  for (let i = 0; i < k; i++) {
    let maxIdx = i
    let max = nums[i]
    for (let j = i + 1; j < nums.length; j++) {
      if (nums[j] > max) {
        maxIdx = j
        max = nums[j]
      }
    }
    if (maxIdx !== i) {
      const tmp = nums[i]
      nums[i] = nums[maxIdx]
      nums[maxIdx] = tmp
    }
  }
  return nums[k - 1]
};
```