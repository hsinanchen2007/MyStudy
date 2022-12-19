### 解题思路


### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.split(/\s+/).filter(item => item.length).reverse().join(' ')
};
```