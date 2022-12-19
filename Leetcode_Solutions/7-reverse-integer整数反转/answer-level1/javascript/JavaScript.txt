### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */var reverse = function(x) {
  // 临界值
  const MAX = Math.pow(2, 31) - 1
  const MIN = Math.pow(-2, 31)
  let result = 0
  // 处理0
  if (x === 0) return 0;
  while(x !== 0) {
    let tmp = x % 10;
    x = parseInt(x / 10);
    result = result * 10 + tmp
  }
  // 处理溢出
  if (result > MAX || result < MIN) {
    return  0
  }
  return result
};
```