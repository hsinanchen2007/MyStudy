### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
   const SIGN = {
        '*' : (a, b) => a * b,
        '/' : (a, b) => Math.trunc(a / b),
        '+' : (a, b) => a + b,
        '-' : (a, b) => a - b
    }
    const stack = [];

    tokens.map(t => {
        if (SIGN[t]) {
            console.log(stack)
            var n1 = stack.pop();
            var n2 = stack.pop();
            var result = SIGN[t](Number(n2), Number(n1));

            stack.push(result);    
        }  else {
            stack.push(t);
        }
    })

console.log(stack)
    return stack[0];
};
```