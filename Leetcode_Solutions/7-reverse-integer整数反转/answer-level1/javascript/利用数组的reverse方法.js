### 解题思路
思路就是先将数字转换为字符串，然后字符串转换为数组，调用数组的反转方法，再转化为字符串，最后乘以正负的系数

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
  const max = Math.pow(2, 31) - 1
  const min = -max - 1
  const flag = x > 0 ? 1 : -1
  const result = Math.abs(x).toString().split('').reverse().join('') * flag
  if (result > max || result < min) {
    return 0
  } else {
    return result
  }
};
```