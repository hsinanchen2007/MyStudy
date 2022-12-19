```js
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let stack = []
    const map = {
        ')': '(',
        ']': '[',
        '}': '{'
    }

    for (let str of s) {
        if (!map[str]) { // 判断是否左括号
            stack.push(str)
        } else if (map[str] !== stack.pop()) { // 左括号进栈，判断前一位是否右括号，否则返回false
            return false
        }
    }
    return !stack.length // 字符串遍历完，如果不是空栈就证明不是一一匹配的括号组合
};
```