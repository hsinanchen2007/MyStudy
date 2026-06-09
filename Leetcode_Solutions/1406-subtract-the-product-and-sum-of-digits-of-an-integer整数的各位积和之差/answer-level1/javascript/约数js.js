### 解题思路
虽然使用了约数的方法逐个计算各位的积和，但时间还是有点久。以后再改进

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    let unit = 0
    let sum = 0
    let product = 1
    while (n!=0){
        unit = n%10
        n = parseInt(n/10)
        sum += unit
        product *= unit
    }
    return product-sum
};
```