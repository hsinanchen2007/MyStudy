### 解题思路
三种情况，分别写正则...

### 代码

```javascript
/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function(word) {
    return /^[A-Z]*$/.test(word) || /^[a-z]*$/.test(word) || /^[A-Z][a-z]+$/.test(word)
};
```