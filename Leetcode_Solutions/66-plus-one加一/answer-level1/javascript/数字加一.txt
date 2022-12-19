### 解题思路
此处撰写解题思路
参考的别人的题解。BigInt(string) 能把字符串转成正确的数字形式
因为string 有可能超出安全数字长度
### 代码

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
var newN = BigInt(digits.join('')) + 1n + '';
return newN.split('').map(item => Number(item));
};
```