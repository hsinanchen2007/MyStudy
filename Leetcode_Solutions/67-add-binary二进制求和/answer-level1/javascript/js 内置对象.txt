js Number超过 2^53-1 会溢出
有一个 Bigint 对象可以处理
不过两个对象不通用

搞定

```
var addBinary = function (a, b) {
    let numA
    let numB
    if (a.length >= 53 || b.length >= 53) {
        numA = BigInt("0b" + a)
        numB = BigInt("0b" + b)
    } else {
        numA = parseInt(a, 2)
        numB = parseInt(b, 2)
    }
    return (numA + numB).toString(2)
};
```

