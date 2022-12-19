### 解题思路

### 代码

```javascript
/**
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 */
const fun = (num) => {
    let arr = num.toString().split("");
    return arr.every(el => num % el === 0)           
}
var selfDividingNumbers = function (left, right) {
    let arr = [];
    for (let i = left; i <= right; i++) {
        arr.push(i);
    }
    return arr.filter(el => fun(el))          
};
```