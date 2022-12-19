```
/**
 * @param {string} 
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    const strArr = s.match(/\b[a-zA-Z]+\b/g);
    return strArr === null ? 0 : strArr[strArr.length - 1].length;
};
```
