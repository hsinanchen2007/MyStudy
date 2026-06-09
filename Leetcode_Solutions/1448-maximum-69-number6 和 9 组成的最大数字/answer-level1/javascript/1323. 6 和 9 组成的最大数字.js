### 解题思路

从高位开始判断，如果有 ``6`` 就反转成为 ``9`` 并直接返回结果，否则一直往下循环。

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var maximum69Number  = function(num) {
    let str = num.toString()
    for (let i = 0; i < str.length; i++) {
        if (str.charAt(i) == 6) {
            return parseInt(str.slice(0, i) + 9 + str.slice(i + 1))
        }
    }
    return num
};
```