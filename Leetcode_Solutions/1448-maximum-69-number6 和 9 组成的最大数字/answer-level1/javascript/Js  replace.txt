### 解题思路
因为只能翻转一次，所以将最高位的6替换成9即可得到最大。

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var maximum69Number = function (num) {
  return Number(String(num).replace('6','9'))
};
```