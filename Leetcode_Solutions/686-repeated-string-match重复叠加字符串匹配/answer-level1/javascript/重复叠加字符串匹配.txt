A 至少要重复times次，A2的长度才会不小于B的长度，这时才去判断B是否是A2的子集；
如果A2不包含子集B，我们需要再次判断A重复（times+1）次得到的A3是否包含子集B

```js
var repeatedStringMatch = function(A, B) {
    let times = Math.ceil(B.length / A.length);
    let A2 = A.repeat(times);
    let A3 = A2 + A;
    if (A2.indexOf(B) !== -1) {
        return times;
    } else if (A3.indexOf(B) !== -1){
        return times + 1
    } else {
        return -1
    }
};

```
