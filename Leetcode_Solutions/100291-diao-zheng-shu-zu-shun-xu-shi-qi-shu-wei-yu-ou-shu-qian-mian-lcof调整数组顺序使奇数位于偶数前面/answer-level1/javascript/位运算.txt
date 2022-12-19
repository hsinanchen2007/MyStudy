### 解题思路
位运算

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var exchange = function(arr) {
   const res = [];

  arr.forEach(item => {
    item & 1 ? res.unshift(item) : res.push(item);
  });
  return res;
};
```