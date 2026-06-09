### 解题思路
本质还是使用快速幂求出10^n次方
快速幂：将指数转换成二进制形式，例如a13=a2^0+2^2+2^3=a2^0a2^2a2^3

### 代码

```javascript
var printNumbers = function(n) {
    let base = 10, sum = 1, res = [];

    while (n != 0) {
        if ((n & 1) == 1) {
            // 如果当前二进制最后一位为1
            sum *= base;
        }
        n >>= 1;
        base *= base;
    }
    let i = 1;

    while (i < sum) {
        res.push(i++);
    }
    return res;
};
```