栈:  
    1.初始化栈并循环字符串S  
    2.如果字符串S[i]和栈顶元素相同,则出栈,否则入栈  
    3.返回栈的字符串格式  

```js
/**
 * @param {string} S
 * @return {string}
 */
var removeDuplicates = function (S) {
    let stack = [];
    for (let i = 0, sLen = S.length; i < sLen; i++) {
        if (stack.length && stack[stack.length - 1] === S[i]) {
            stack.pop();
        } else {
            stack.push(S[i]);
        }
    }
    return stack.join('');
};
```