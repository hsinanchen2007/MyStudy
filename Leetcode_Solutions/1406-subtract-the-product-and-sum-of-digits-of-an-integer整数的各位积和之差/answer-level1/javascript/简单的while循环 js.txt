### 解题思路
别问 问就直接看代码

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    let sum = 0
    let product = 1
    while(n){
        let ele = n % 10
        sum = sum + ele
        product = product * ele
        n = (n - ele) / 10
    }
    return product - sum
};
```