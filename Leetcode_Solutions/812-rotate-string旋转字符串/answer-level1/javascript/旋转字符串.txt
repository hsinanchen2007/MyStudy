*法一*

```js
var rotateString = function(A, B) {
    if (A === '' && B === '') {
        return true
    }
    let len = A.length - 1;
    while(len > 0) {
        let A1 = A.slice(0,1)
        let A2 = A.slice(1,A.length)
        A = A2+ A1;
        if (A === B) {
            return true;
        }
        len--
    }
    return false
};
```

*法二*

思路：只需比较一下两个字符串的长度，然后判断A + A中是否存在B就ok，因为A + A中已经包含了所有可能的移动情况

```js
var rotateString = function(A, B) {
    if (A.length === B.length && (A + A).includes(B)) {
        return true
    }
    return false
};
```

