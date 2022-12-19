5行代码结束战斗
```js
var minimumLengthEncoding = function(words) {
    return words.sort((a, b) => b.length - a.length)
    .reduce((t, s) => {
        if(!t.includes(s + '#')) t += s + '#';
        return t;
    }, '').length;
};
```
