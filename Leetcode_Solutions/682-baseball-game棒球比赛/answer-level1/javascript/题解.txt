### 解题思路
基础版

### 代码

```javascript
/**
 * @param {string[]} ops
 * @return {number}
 */
var calPoints = function(ops) {
  let result = []
  let pre1
  let pre2
  ops.forEach(item => {
    switch (item) {
      case 'C':
        result.pop()
        break
      case 'D':
        pre1 = result.pop()
        result.push(pre1, pre1 * 2)
        break
      case '+':
        pre1 = result.pop()
        pre2 = result.pop()
        result.push(pre2, pre1, pre2 + pre1)
        break
      default:
        result.push(item * 1)
    }
  })
  return result.reduce((total, num) => {
    return total + num
  })
};
```