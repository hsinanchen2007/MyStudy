### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    if (!s) return true;
    if (s.length === 1) return false;
    let hash = {
        '(': ')',
        '{': '}',
        '[': ']',
    },
    stack = [s[0]];
    for (let i = 1; i < s.length; i++) {
        if (hash[stack[stack.length - 1]] === s[i]) {
            stack.pop();
        } else {
            stack.push(s[i])
        }
    }
    return !stack.length;
};
```