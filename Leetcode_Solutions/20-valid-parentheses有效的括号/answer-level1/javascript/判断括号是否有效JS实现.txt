### 解题思路
经典的栈问题，通过数组简单实现。最后栈为空即为合法。效率高。

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let stack = []
    let map = {
        '(': ')',
        '{': '}',
        '[': ']'
    }
    let slen = s.length
    for (let i = 0; i < slen; i++) {
        if (s[i] in map) {
            stack.push(map[s[i]])
        } else {
            if (stack[stack.length - 1] === s[i]) {
                stack.pop()
            } else {
                return false
            }
        }
    }
    return stack.length === 0
};
```