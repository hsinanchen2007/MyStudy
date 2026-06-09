### 解题思路
先转换成字符串，再转成数组

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    var x = x + '';
    var le = x .split('').length;
    var right = le%2 === 0 ? le/2 : (le+1)/2;
    var left = le%2 === 0 ? le/2 -1 : (le-1)/2 -1;
    if(le === 1) {
        return true;
    }
    for(var i = 0;i<= left; i++){
        if(x[i] !== x[le-i-1]) {
             return false;
        } 
    } 
    return true;
};
```