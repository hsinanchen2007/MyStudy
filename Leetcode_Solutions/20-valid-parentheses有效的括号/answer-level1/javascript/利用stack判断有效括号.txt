### 解题思路
如果是合法的括号字符串，那么字符串中出现的右括号时，栈顶元素一定可以匹配到相应的左括号。

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    Array.prototype.last = function() {
        return this[this.length - 1]
    }

    var stack = []
    for (var i=0; i<s.length; i++) {
        var top = stack.last()
        if (top == '(' && s[i] == ')') {
            stack.pop()
        } else if (top == '[' && s[i] == ']') {
            stack.pop()
        } else if (top == '{' && s[i] == '}') {
            stack.pop()
        } else {
            stack.push(s[i])
        }
    }

    return stack.length == 0
};
```