### 解题思路
因为js的number 最大值（9007 1992 5474 0992），那么可以用BigInt来进行大数值运算

### 代码

```javascript
var plusOne = function(digits) {
  const digits_str = digits.join('')
  const res_num = (BigInt(digits_str) + BigInt(1)).toString()
  return res_num.split('').map((str) => Number(str))
};
```