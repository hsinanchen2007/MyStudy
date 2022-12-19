### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var trailingZeroes = function(n) {
  let count = 0
  while(n>0) {
     count+=Math.floor(n/5)
     n = Math.floor(n/5) 
  }
  return count
};
```