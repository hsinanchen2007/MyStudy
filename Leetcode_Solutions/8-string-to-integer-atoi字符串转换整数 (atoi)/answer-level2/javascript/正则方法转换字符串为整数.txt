### 解题思路
1. 使用正则表达式匹配正确的字符串格式
2. 不符合格式则直接返回0；符合状态规则，解析与整数相关的字符串

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    const INT_MAX = 2**31 -1;
    const INT_MIN = (-2)**31;

    let match = str.match(/\s*(?:([+|-]?)([^\d]*)([\d]+))(?:.*)/);
    console.log(match);
    if (match && match[2].length === 0) {
        let sign = 1,
            value = 0,
            i = 0;
        while (i < match[3].length) {
            value = value * 10 + (match[3][i++]-0);
        }

        if (match[1] == '-' ) {
            sign = -1;
            return Math.max(sign*value, INT_MIN);
        } else {
            return Math.min(sign*value, INT_MAX);
        }
    }
    return 0;
};
```