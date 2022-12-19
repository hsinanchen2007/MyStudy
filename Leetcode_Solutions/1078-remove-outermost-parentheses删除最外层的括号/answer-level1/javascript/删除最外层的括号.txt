借助栈原语化分解后删除最外层括号
```js
var removeOuterParentheses = function(S) {
    let arr = [];
    let k = 0;
    let primitives = []
    for (let i = 0; i < S.length; i++) {
        if (S[i] == '(') {
            arr.push('(')
        } else {
            arr.pop()
        }
        if (arr.length == 0) {
            primitives.push(S.substring(k,i + 1))
            k = i + 1
        }
    }
    return primitives.map((item) => item.slice(1,item.length - 1)).join('')
};
```
