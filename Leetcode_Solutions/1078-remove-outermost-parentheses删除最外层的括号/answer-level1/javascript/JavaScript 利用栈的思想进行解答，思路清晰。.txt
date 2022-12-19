```
/**
 * @param {string} S
 * @return {string}
 */
var removeOuterParentheses = function(S) {
    let stack = []
    let result = ''
    let index = 0
    for (let i = 0; i < S.length; i++) {
        if (S[i] === '(') stack.push('(')
        else stack.pop('(')
        // 栈为空则说明找到一个完整的最外层括号，截取外层括号里面的内容即可
        if (!stack.length) {
            result += S.substring(index + 1, i)
            index = i + 1
        }
    }
    return result
};
```