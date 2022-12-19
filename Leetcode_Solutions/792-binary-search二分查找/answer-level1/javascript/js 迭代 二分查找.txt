![image.png](https://pic.leetcode-cn.com/7d80e8d665bc3f1a06348e0f1309d9cac51a288a98bd23b0280de8b78b89e413-image.png)

### 解题思路
此处撰写解题思路

### 代码
```js
迭代二分查找
```

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

var search = function(nums, target) {
  let ans = -1,
      low = 0,
      high = nums.length - 1;
  
  while (low <= high) {
    let mid = low + Math.floor((high - low) / 2);
    
    if (nums[mid] === target) {
      ans = mid;
      break;
    }
    
    if (nums[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  
  return ans;
};
```