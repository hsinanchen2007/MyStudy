### 解题思路
使用一个栈来压缩字符串

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    const len = S.length
    if (len < 2) {
        return S
    }
    let stack = [S[0]]
    let res = ''
    for (let i = 1; i < len; i ++) {
        if (stack[stack.length - 1] !== S[i]) {
            res += `${stack[0]}${stack.length}`
            stack = []
        }
        stack.push(S[i])
    }
    if (stack.length) {
        res += `${stack[0]}${stack.length}`
    }
    return res.length < len ? res : S
};
```