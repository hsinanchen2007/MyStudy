```js
var evalRPN = function(tokens) {
    // 遍历数组, 遇到数值压栈, 遇到运算符连续出栈两次, 将计算结果入栈
    const stack = [];

    tokens &&
        tokens.forEach(item => {
            if (/^[+\-*/]$/.test(item)) {
                stack.push(calc(item, stack.pop(), stack.pop()));
            } else {
                stack.push(item);
            }
        });

    return stack.pop() || 0;
};

function calc(action, a, b) {
    a = Number(a);
    b = Number(b);

    switch (action) {
        case "+":
            return b + a;
        case "-":
            return b - a;
        case "*":
            return b * a;
        case "/":
            // 坑: Math.floor对负数来说并非取整
            return Math.trunc(b / a);
        default:
            return b + a;
    }
}
```