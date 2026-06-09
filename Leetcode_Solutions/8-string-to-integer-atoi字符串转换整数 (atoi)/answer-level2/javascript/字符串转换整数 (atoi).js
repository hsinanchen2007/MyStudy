^: 以什么开头
？: 匹配前面的子表达式零次或一次。例如，"do(es)?" 可以匹配 "do" 或 "does" 中的"do" 。? 等价于 {0,1}。


```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    let s = str.trim().match(/^[+|-]?\d+/g);
    if(!s || s.length===0) return 0;
    let num = parseInt(s[0]);
    num = num > (Math.pow(2,31) - 1) ?  (Math.pow(2,31) - 1) :  num < Math.pow(-2,31) ? Math.pow(-2,31): num;
    return num;   
};
```