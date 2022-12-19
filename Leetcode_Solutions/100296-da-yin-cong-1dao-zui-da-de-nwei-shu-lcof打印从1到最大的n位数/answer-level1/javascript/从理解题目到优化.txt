### 解题思路
1. 考察 1-9 整数中 小于 10的指数

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var printNumbers = function(n) {
    //这道题考察 1-9整数中 小于 10整数的指数
    let result = [];
    for(let i = 1,pow = Math.pow(10,n);i<pow;i++){
        result.push(i)
    }

    return result
};

var printNumbers2 = function(n) {
    //幂的结果
    let res = 1;
    //奇数
    let x = 10;
    //模版，指数
    while (n) {
        if (n & 1) {
            res = res * x;
        }
        x = x * x;
        n = n >> 1;
    }

    const result = [];
    for (let i = 1; i < res; i++) {
        result.push(i);
    }
    return result
};

```