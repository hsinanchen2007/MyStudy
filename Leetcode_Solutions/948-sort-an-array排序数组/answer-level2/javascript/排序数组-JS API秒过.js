### 解题思路
![image.png](https://pic.leetcode-cn.com/7560e36f2b05d34e76e08124a99ad17515f5fd00933845665815ec785ab12250-image.png)

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
   return nums.sort((a, b) => a - b);
};
```