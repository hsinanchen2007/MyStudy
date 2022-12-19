![image.png](https://pic.leetcode-cn.com/8baf672a28b6699dfd1f6905921c0aacb559ab4cae84c0f2001da85e8a0bdd8a-image.png)

### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */

var findNumbers = function(nums) {
  let count = 0;
  
  for (let i = 0, len = nums.length; i < len; i++) {
    if (nums[i].toString().length % 2 === 0) {
      count++;
    }
  }
  
  return count;
};
```