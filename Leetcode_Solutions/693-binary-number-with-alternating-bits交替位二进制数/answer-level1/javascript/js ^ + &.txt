![image.png](https://pic.leetcode-cn.com/c5b8c76f699c33fc6347a1d41745dd43f19cc9da9a8aee52ef99fface294623b-image.png)

### 解题思路
```js
  1. n 和 n >> 1 进行 ^ 操作，赋值给 n
        1 0 1
        0 1 0
      = 1 1 1
      
  2. n & n + 1 === 0
        1 1 1
      1 0 0 0
    = 0 0 0 0
    
  总结：如果是交替二进制数，那么这两步运算一定为 0
```

### 代码

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */

var hasAlternatingBits = function(n) {
  n = n ^ (n >> 1);
  return (n & (n + 1)) === 0;
};
```