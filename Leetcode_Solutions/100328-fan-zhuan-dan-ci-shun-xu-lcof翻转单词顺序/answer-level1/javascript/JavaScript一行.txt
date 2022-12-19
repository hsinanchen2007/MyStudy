### 解题思路
这种字符串处理还是用内置函数比较方便。

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.split(' ').filter(a => a.length > 0).reverse().join(' ')
};
```