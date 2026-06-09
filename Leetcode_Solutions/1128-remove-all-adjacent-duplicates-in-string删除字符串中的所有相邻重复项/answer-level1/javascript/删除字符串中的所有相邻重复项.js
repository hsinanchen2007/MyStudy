*法一：正则匹配*

缺点： 速度优点太慢了

```js
var removeDuplicates = function(S) {
    let pat = /([a-z])\1/
    while(pat.test(S)) {
        S = S.replace(pat.exec(S)[0], '')
    }
    return S
};
```

*法二：借用顺序栈*

```js
var removeDuplicates = function(S) {
    let arr = []
    for (let i = 0; i < S.length; i++) {
        let index = arr.length > 0 ? arr.length - 1 : 0;
        if (S[i] == arr[index]) {
            arr.pop()
        } else {
            arr.push(S[i])
        }
    }
    return arr.join('')
};
```

