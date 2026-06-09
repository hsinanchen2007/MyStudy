```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {
  // 直接先去除两头空格就不用考虑两头有空格的情况了
  s = s.trim()
  //           加上^$确保匹配的是整个字符串而不是字符串中的一部分
  //                    1. 和.1都是true，所以要这样判断
  //                                       后面是e的部分e后面跟的数字可正可负但是必须为整数
  const flag = /^([-+]?(\d+(\.\d*)?|\.\d+)(e[-+]?\d+)?)$/.test(s)
  return flag
};
```
