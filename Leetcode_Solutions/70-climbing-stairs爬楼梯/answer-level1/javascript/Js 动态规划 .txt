### 解题思路
动态规划 简单直接

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
  let arr = [1,2];
  
  for(let i = 2; i < n; i++) {
      arr[i] = arr[i-1] + arr[i-2]
  }

  return arr[n-1]
};
```