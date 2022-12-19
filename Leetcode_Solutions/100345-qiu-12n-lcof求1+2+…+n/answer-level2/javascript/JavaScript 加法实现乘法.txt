### 解题思路

核心思路是利用公式：sum = ((n + 1) * n ) / 2

这里面有一个除法，有一个乘法。

1. 除2，可以用位运算向右移位代替
2. 乘法，可以用加法模拟

### 代码

```javascript
var sumNums = function(n) {
    return multi(n, n+1, 0) >> 1
};

function multi(a, b, sum) {
    if (b === 0) return sum

    if (b & 1) return multi(a, b-1, sum + a)
    return multi(a + a, b >> 1, sum)
}
```