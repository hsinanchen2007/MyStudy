### 解题思路
正则匹配 应该还能优化下


### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
let max = 2147483648 - 1;
let min = -2147483648;
var myAtoi = function(str) {
    let s = str.trim();
    let minus = s.charAt(0) === '-';
    s = minus || s.charAt(0) === '+' ? s.substr(1) : s;

    let reg = /^\d+/;
    let res = reg.exec(s);
    if(res) {
        let num = parseInt(res[0]);
        num = minus ? -num : num;
        if(num > max) return max;
        else if(num < min) return min;
        else return num;
    } else {
        return 0;
    }
};
```