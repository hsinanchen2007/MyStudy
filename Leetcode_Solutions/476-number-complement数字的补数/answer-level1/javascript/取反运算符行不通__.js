### 解题思路
对按位运算符颇为生疏, 明明有个取反运算符~, 就是结果不对
### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function(num) {
   num = num.toString(2)  // 转为 2进制  比如5 变成 101
   num = num.split('').map(t=>t==1?0:1).join('')  // 取反 101 => 010 , 之前以为直接用取反运算符~  直接取反, 发现结果都不对
   return parseInt(num,2) // 再把二进制转为十进制
};
```