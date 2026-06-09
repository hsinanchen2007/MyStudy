*法一：*

只与最后一个元素0的前面的连续1的个数有关系。

```js
var isOneBitCharacter = function(bits) {
    let last1count = 0;
    for (let i = bits.length - 2; i >= 0; i--) {
        if(bits[i] === 1) {
            last1count++;
        } else {
            break;
        }
    }
    return last1count % 2 === 0 
};
```

*法二*

```js
var isOneBitCharacter2 = function(bits) {
    let pat = /^(10|11|0)*0$/;
    let str = bits.join('');
    return pat.test(str)
};
```

