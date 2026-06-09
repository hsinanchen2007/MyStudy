![image.png](https://pic.leetcode-cn.com/e3f13a67126fcdf9e5c1af1cf9ee4723468dba55b1f49dc46ebcf8e4642ac931-image.png)

### 解题思路
```js
  参考作者：「王尼玛」
  利用额外指针，先把所有非 0 的数，从头到尾放
  剩下的全部填充为 0
```

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
  let n = nums.length,
      j = 0;
  
  for (let i = 0; i < n; i++) {
    if (nums[i] !== 0) {
      nums[j] = nums[i];
      j++;
    }
  }
  
  for (let i = j; i < n; i++) {
    nums[i] = 0;
  }
};
```