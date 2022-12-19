```
/**
 * @param {string} S
 * @return {string}
 */
var removeDuplicates = function(S) {
    var stack = []
    for(var i = 0; i < S.length; i++) {
        // 栈顶与当前值相同，出栈
        if (stack[stack.length - 1] === S[i]) {
            stack.pop()
        // 入栈
        } else {
            stack.push(S[i])
        }
    }
    return stack.join('')
};
```
