思路：利用BigInt解决溢出的问题
```js
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    return (BigInt('0b' + a) + BigInt('0b' + b)).toString(2);
};
```
![9A49D7D7-8DC0-4b44-9C6E-C81B7620998B.png](https://pic.leetcode-cn.com/902786efdef112f553484b2ff7874f1e4659b5c863496b15f2a2d9588b8e0f2c-9A49D7D7-8DC0-4b44-9C6E-C81B7620998B.png)
