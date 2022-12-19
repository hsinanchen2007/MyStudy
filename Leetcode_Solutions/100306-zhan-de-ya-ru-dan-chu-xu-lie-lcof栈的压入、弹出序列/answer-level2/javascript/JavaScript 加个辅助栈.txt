
添加一个辅助栈

```js
var validateStackSequences = function(pushed, popped) {
    let fuzhu = [];
    for (let i = 0; i < pushed.length; ++i) {
        fuzhu.push(pushed[i]);
        while (fuzhu.length > 0 && fuzhu[fuzhu.length - 1] === popped[0]) {
            fuzhu.pop();
            popped.shift();
        }
    }
    return popped.length === 0;
};
```