### 解题思路
最初的代码是： 
```
var plusOne = function(digits) {
    var newnumber = parseInt(digits.join(''))+1
    return newnumber.toString().split("").map(Number)
};
```
结果没有考虑到JS中的Number类型只能安全地表示- 9007199254740991(-(2^53-1))和 9007199254740991（(2^53-1)），任何超出此 范围的整数值都可能失去精度。所以BigInt就完美解决啦！（BigInt 是 JavaScript 中的一个新的数字类型，可以用任意精度表示整数。使用 BigInt，即使超出 Number 的安全整数范围限制，也可以安全地存储和操作大整数。）

### 代码

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    var newnumber =BigInt(digits.join('')) + 1n
    return newnumber.toString().split("").map(BigInt)
};
```