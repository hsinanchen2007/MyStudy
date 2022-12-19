垃圾题
```js
var maxDepthAfterSplit = function(seq) {
    const res = [];
    let level = 0;
    for(let i = 0; i < seq.length; i++) {
        if (seq[i] === '(') res.push(++level % 2);
        else res.push(level-- % 2);
    }
    return res;
};
```
