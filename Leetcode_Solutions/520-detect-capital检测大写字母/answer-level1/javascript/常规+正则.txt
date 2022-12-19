### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function(word) {
    if(word===word.toUpperCase()||word===word.toLowerCase()||(word.length>1&&word===(word[0].toUpperCase()+word.slice(1).toLowerCase()))){return true;}
    return false;
};
```
正则匹配
```
var detectCapitalUse = function(word) {
    let reg1 = /^[A-Z]*$/;
    let reg2 = /^[A-Z][a-z]*$/;
    let reg3 = /^[a-z]*$/;
    return reg1.test(word) || reg2.test(word) || reg3.test(word);
};
```
