```
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    // 替换掉e，防止parseFloat将 “12e16” 认成科学计数法
    str = str.trim().replace(/e/g, 'a');
    let num = parseFloat(str);
    num = Number.isNaN(num) ? 0 : num;
    const edge = Math.pow(2, 31);
    return Math.max(-edge, Math.min(edge - 1, num));
};
```
