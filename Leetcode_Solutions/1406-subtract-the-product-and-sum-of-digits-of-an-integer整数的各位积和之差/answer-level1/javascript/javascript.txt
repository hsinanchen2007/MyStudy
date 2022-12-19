### 解题思路
数字转子串转数组，用reduce方法结算乘积与和积，然后计算

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    let array_n = n.toString().split("")
    let totalN =  array_n.reduce((x,y) =>{
        return parseInt(x) + parseInt(y)
    })
    let reduceN = array_n.reduce((x,y) =>{
        return x * y
    })
    return reduceN - totalN;
};
```