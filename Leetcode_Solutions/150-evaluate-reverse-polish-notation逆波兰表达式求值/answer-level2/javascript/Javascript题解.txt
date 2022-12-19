### 题解
其实思路很简单，就是用栈存储数字，如果遇到的是运算符，则将栈顶的两个元素取出来，然后执行运算符对应的操作，需要注意的是，如果是除法操作，先出栈的为除数，后出栈的为被除数，其它操作都满足交换律，所以不需要在意出栈的数字的顺序。每一步运算结束后，需要将结果再压入栈，以此类推。
我在代码里用对象将每个操作符对应的运算包了起来，因此如果是运算符，只需要直接调用对象里对应的方法即可。
代码如下：
```
const SIGN = {
    '*' : (a, b) => a * b,
    '/' : (a, b) => Math.trunc(a / b),
    '+' : (a, b) => a + b,
    '-' : (a, b) => a - b
}
var evalRPN = function(tokens) {
    const stack = [];
    tokens.forEach(item => {
        if (item in SIGN){
            const b = stack.pop();
            const a = stack.pop();
            const res = SIGN[item](a, b);
            stack.push(res);
        }
        else stack.push(Number(item));
    })
    return stack.pop();
};
```
有问题，欢迎指正，谢谢。
