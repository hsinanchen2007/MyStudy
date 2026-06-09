![image.png](https://pic.leetcode-cn.com/63c20b16282d217d7630dbae9e6b56f39a87fdfc695e102fc00f6af4347e153f-image.png)

### 解题思路
```js
思路：

两次二分查找，查找 target 的左右边界，如果都找到，返回答案，否则，返回 -1

- 左边界：target 为数组的第一个值，或者 target 左边的元素不等于 8
- 右边界：target 为数组的最后一个值，或者 target 右边的元素不等于 8
```

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

var searchRange = function(nums, target) {
  let ans = [-1, -1],
      len = nums.length,
      left = 0,
      right = len - 1;
  
  // 迭代查找右边界
  while (left <= right) {
    let mid = left + Math.floor((right - left) / 2);
    
    if (nums[mid] === target && (mid === len - 1 || nums[mid + 1] > target)) {
      ans[1] = mid;
      break;
    }
    
    if (nums[mid] <= target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  
  // 迭代查找左边界
  left = 0;
  while (left <= right) {
    let mid = left + Math.floor((right - left) / 2);
    
    if (nums[mid] === target && (mid === 0 || nums[mid - 1] < target)) {
      ans[0] = mid;
      break;
    }
    
    if (nums[mid] >= target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  
  return (ans[0] === -1 || ans[1] === -1) ? [-1, -1] : ans;
};
```