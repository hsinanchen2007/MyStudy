### 解题思路
将数字转成字符串，然后再进行正负判断，有负数则将负数符号摘出来，再将字符串转数组，最后再利用数组的reverse方法，得到反转之后的字符串，将字符串进行数字转换，最后对是否溢出进行判断，返回最终结果

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
let strX = x.toString();
let result = '';
if(strX.includes('-')) {
result += '-'
strX.slice(0, 1);
}
const tempResult = strX.split('').reverse().join('');
result += tempResult;
result = parseInt(result, 10);
if (result > Math.pow(2, 31) -1 || result < Math.pow(-2, 31)) {
   result = 0 
}
return result;
};
```