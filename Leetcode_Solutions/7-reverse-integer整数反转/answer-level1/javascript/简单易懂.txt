### 解题思路
- 判断正负，取符号
- 反转前后都要判断是否超出范围
- 把数字转成字符串再专成数组，调用 reverse 方法，再转成字符串
- 加上符号

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    if (Math.abs(x) > Math.pow(2, 31) - 1) return 0;
    let flag = x<0?-1:1;
    let res = String(Math.abs(x)).split('').reverse().join('');
    if (res > Math.pow(2, 31) - 1) return 0;
    return flag * res;
};
```