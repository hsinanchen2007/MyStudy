```
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    var m = {
        '(': ')',
        '{': '}',
        '[': ']'
    }
    var stack = []
    for (var i = 0; i < s.length; i++) {
        // 当前元素与栈顶 对应，出栈
        if(s[i] === m[stack[stack.length - 1]]) {
            stack.pop()
        } else {
            // 否则入栈
            stack.push(s[i])   
        }
    }
    return !Boolean(stack.length)
};
```
