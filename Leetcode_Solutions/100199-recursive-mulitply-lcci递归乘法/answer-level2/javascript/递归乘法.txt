### 解题思路
以A和B中的最小值作为递归变量

### 代码

```javascript
/**
 * @param {number} A
 * @param {number} B
 * @return {number}
 */
var multiply = function(A, B) {
    var tempMin = Math.min(A, B)
    var tempMax = A + B - tempMin
    if(tempMin === 1) return tempMax
    return tempMax + multiply(tempMin-1, tempMax)
};
```