### 解题思路
看代码

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var strToInt = function(str) {
    /**
     * parseInt:将一个字符串 string 转换为 radix 进制的整数， radix 为介于2-36之间的数。
     */
   return Math.max(Math.min(parseInt(str) || 0, 2147483647), -2147483648);
};
```