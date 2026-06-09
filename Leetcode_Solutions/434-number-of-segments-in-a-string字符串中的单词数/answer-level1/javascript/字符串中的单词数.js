*法一： trim()+split()*
```js
var countSegments = function(s) {
    s = s.trim();
    if (s === '') return 0
    return s.split(/\s+/).length
};
```

*法二：遍历*

```js
var countSegments = function(s) {
    let count = 0;
    s += ' ';
    for (let p = 1; p < s.length; p++){
        if (s[p - 1] !== s[p] && s[p] === ' ') count++;
    }
    return count;
};
```

