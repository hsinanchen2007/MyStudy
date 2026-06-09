### 解题思路
不能用加减，那用对数咯
![对数.svg](https://pic.leetcode-cn.com/3ba7f913d5360ecda6b49d5be1f7ea4cdfa37d4b599a3d52ff7c7de2b6a44942-%E5%AF%B9%E6%95%B0.svg)
\,\log_{\theta}xy=\log_{\theta}x+\log_{\theta}y
### 代码

```javascript
/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var getSum = function (a, b) {
  return Math.log((Math.exp(a/10e10)*Math.exp(b/10e10)))*10e10
};
};
```
### 
JavaScript位运算符补课网址
https://www.w3school.com.cn/js/js_bitwise.asp
### 代码
```javascript
/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var getSum = function (a, b) {
  while (b !== 0) {
    let temp = a ^ b;
    b = (a & b) << 1;
    a = temp;
  }return a
};
```
### 解题思路
浓缩为一行
### 代码
```javascript
/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var getSum = function (a, b) {
  return (a&b)?getSum(a^b,(a&b)<<1):a^b
};
```
