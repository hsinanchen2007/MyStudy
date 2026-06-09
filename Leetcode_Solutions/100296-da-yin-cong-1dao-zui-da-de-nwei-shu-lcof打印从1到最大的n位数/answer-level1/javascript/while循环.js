### 解题思路


### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var printNumbers = function(n) {
    let arr = [];
    let result = '1';
    let number = 1;
    while (result.length <= n) {
        arr.push(number++);
        result = number +='';
    }
    return arr;
};
```