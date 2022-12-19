使用正则表达式

```js
var backspaceCompare = function(S, T) {
    let pat = /([\w]#)/;
    let pat2 = /^#+/;
    while(/#/.test(S)) {
        S = S.replace(pat, '').replace(pat2, '')
    }
    while(/#/.test(T)) {
        T = T.replace(pat, '').replace(pat2, '')
    }
    return S === T
};
```


```js
var backspaceCompare = function(S, T) {
    let pat = /.?\#/;
    while(/#/.test(S)) {
        S = S.replace(pat, '')
    }
    while(/#/.test(T)) {
        T = T.replace(pat, '')
    }
    return S === T
};
```

