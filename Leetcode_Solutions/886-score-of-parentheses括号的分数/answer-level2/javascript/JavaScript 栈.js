### 解题思路
使用栈解决
### 代码

```javascript
/**
 * @param {string} S
 * @return {number}
 */
var scoreOfParentheses = function(S) {
    const stack = []
    const len = S.length
    for (let i = 0; i < len; i++) {
        // 如果是（直接入栈
        if (S[i] === '(') {
            stack.push('(')
        // 如果栈顶是（说明找到一个括号，把栈内括号替换为1
        } else if (stack[stack.length - 1] === '(') {
                stack.pop()
                stack.push(1)
        // 如果栈顶不是（，字符是），说明栈顶是数字
        } else {
            let a = stack.pop()
            let sum = 0
            // 累加（）值
            while(a !== '(') {
                sum += a
                a = stack.pop()
            }
            // 外部（）相当于乘以2
            stack.push(sum * 2)
        }
    }
    return stack.reduce((a, b) => a + b)
};
```