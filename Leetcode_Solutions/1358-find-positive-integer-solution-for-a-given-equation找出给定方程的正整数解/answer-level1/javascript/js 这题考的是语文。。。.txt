![image.png](https://pic.leetcode-cn.com/287fb27250ef904fa34e73f8957633223c3132e7718ba4d278e9baee3f623c45-image.png)

### 解题思路
```js
鬼题目
```

### 代码

```javascript
/**
 * // This is the CustomFunction's API interface.
 * // You should not implement it, or speculate about its implementation
 * function CustomFunction() {
 *
 *     @param {integer, integer} x, y
 *     @return {integer}
 *     this.f = function(x, y) {
 *         ...
 *     };
 *
 * };
 */
/**
 * @param {CustomFunction} customfunction
 * @param {integer} z
 * @return {integer[][]}
 */

var findSolution = function(customfunction, z) {
  let ans = [];
  
  for (let i = 1; i <= z; i++) {
    for (let j = 1; j <= z; j++) {
      if (customfunction.f(i, j) === z) {
        ans.push([i, j]);
      }
    }
  }
  
  return ans;
};
```