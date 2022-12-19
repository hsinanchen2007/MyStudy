```
/**
 * @param {string[]} ops
 * @return {number}
 */
var calPoints = function(ops) {
    var stack = []
    for (var i = 0; i < ops.length; i++) {
        if (ops[i] === '+') {
            stack.push(parseInt(stack[stack.length - 1], 10) + parseInt(stack[stack.length - 2], 10))
        } else if (ops[i] === 'D') {
            stack.push(2 * parseInt(stack[stack.length - 1], 10))
        } else if (ops[i] === 'C') {
            stack.pop()
        } else {
            stack.push(ops[i])
        }
    }
    return stack.reduce(function(total, num) {
        return parseInt(total, 10) + parseInt(num, 10)
    })
};
```
