### 解题思路
1、找出镜像规律
2、递归求解
3、操作二进制字符串，最后再转成10进制数字

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var grayCode = function(n) {
  let make = (n) => {
    if (n === 0) return ['0']
    if (n === 1) return ['0', '1']

    let prev = make(n - 1)
    let result = []
    let maxIndex = Math.pow(2, n) - 1
    for (let i = 0, len = prev.length; i < len; i++) {
      result[i] = `0${prev[i]}`
      result[maxIndex - i] = `1${prev[i]}`
    }
    return result
  }
  return make(n).map(item => parseInt(item, 2))
};
```