### 解题思路
先判断是否负数，后将值转为数组再倒序最后再转为number

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    // 判断是否负数
    let isNegative = x < 0 ? true : false;
    // 先转为字符串、再转为数组、再数组倒序、再转回为字符串、最后再转回number
    let target = parseInt(x.toString().split('').reverse().join(''));
    target = isNegative ? -target : target;
    let outRange = target < Math.pow(-2, 31) || target > Math.pow(2, 31) -1;
    // 溢出判断
    return outRange ? 0 : target
};
```