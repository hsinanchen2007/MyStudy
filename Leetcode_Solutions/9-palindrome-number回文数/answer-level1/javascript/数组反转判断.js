### 解题思路
数组反转判断

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x<0){
        return false
    }
    xstring = x.toString();
    array = xstring.split('');
    return xstring == array.reverse().join("");

};
```