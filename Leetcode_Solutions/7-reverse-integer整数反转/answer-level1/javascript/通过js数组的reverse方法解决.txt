### 解题思路
思路：调用数组的``reverse``方法反转，需要数字转字符串转数组，再转字符串转整数
```
int.toString().split('').reverse()
```

假如是负数，需要把转换后数组栈尾的``-``放到栈首

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
  const isNeg = x < 0;
  const arr = x.toString().split('').reverse()
  if (isNeg) {
    arr.pop();
    arr.unshift('-');
  }
  const res = parseInt(arr.join(''));
  if (res > Math.pow(2, 31) - 1 || res < Math.pow(-2, 31)) {
    return 0;
  }
  return res;
};
```