### 解题思路
以栈的方法，结合题意进行操作，最后将栈的每一项相加

### 代码

```javascript
/**
 * @param {string[]} ops
 * @return {number}
 */
var calPoints = function (ops) {
    const stack = [];
    let i = 0;
    while (i < ops.length) {
        const temp = [...stack];
        switch (ops[i]) {
            case "+":
                stack.push(temp.pop() + temp.pop());
                break;
            case "D":
                stack.push(temp.pop() *2);
                break;
            case "C":
                stack.pop();
                break;
            default:
                stack.push(+ops[i]);
                break;
        }
        i++;
    }
    return stack.reduce((initialization, current, i) => {
        return initialization + current;
    }, 0);
};
```