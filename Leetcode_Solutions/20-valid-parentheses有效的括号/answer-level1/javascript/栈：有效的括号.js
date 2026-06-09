### 解题思路
先判断两种情况：
1、长度为0
2、长度为奇数 
运用栈的思想：判断栈的最顶部元素是否与字符串中下一个打算要入栈的元素匹配。如果匹配则pop，不匹配则push。循环结束后，如果栈的长度为0则为有效的括号。
### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let length = s.length;
    if (!length) return true;
    if (length % 2 === 1) return false;
    const map = {
        '{': '}',
        '[': ']',
        '(': ')'
    }
    let stack = [s[0]];
    for (let i = 1; i < length; i++) {
        if (map[stack[stack.length - 1]] === s[i]) {
            stack.pop();
        } else {
            stack.push(s[i]);
        }
    }
    return stack.length === 0;
};
```