*法一：二进制异或运算*

`^`：（`x^y`）两二进制上下比较只有位不相等时才取1，否则取零

```js
var hammingDistance = function(x, y) {
    let k = x^y;
    let str = k.toString(2);
    let count = 0;
    for (let i = 0; i < str.length; i++) {
        if (str[i] == 1) {
            count++
        }
    }
    return count
};
```

*法二*

```js
var hammingDistance = function(x, y) {
    let max = x >= y ? x : y;
    let max2 = max.toString(2);
    let x2 = x.toString(2).padStart(max2.length, '0');
    let y2 = y.toString(2).padStart(max2.length, '0');
    let count = 0;
    for (let i = 0; i < max2.length; i++) {
        if (x2[i] !== y2[i]) {
            count++
        }
    }
    return count
};
```