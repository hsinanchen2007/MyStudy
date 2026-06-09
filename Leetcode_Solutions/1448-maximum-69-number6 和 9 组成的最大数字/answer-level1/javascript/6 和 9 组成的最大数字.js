### 解题思路

将第一个 `6` 替换为 `9`。

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var maximum69Number  = function(num) {
    return +num.toString().replace(/6/,9);
};
```