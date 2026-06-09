```js
var addToArrayForm = function(A, K) {
    const Aarr = A.reverse();
    const Karr = K.split('').reverse().map((x) => +x)
    const maxLen = Math.max(Aarr.length, Karr.length)
    let res = []
    let flag = false
    for (let i = 0; i < maxLen; i++) {
        sum = (Aarr[i] ? Aarr[i] : 0) + (Karr[i] ? Karr[i] : 0) + (flag ? 1 : 0)
        flag = sum >= 10
        res.push(sum % 10)
    }
    if (flag) {
        res.push(1)
    }
    return res.reverse()
};
```
