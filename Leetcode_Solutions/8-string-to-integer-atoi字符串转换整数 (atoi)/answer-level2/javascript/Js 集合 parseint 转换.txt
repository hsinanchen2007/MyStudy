### 解题思路
Js 集合 parseint 转换

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    let int = parseInt(str);
    let max = 2**31 - 1;
    let min = -1 * 2**31;
    if(int) {
        if(int > max) int = max;
        if(int < min) int = min; 
    }
    return int ?int : 0; 
};
```