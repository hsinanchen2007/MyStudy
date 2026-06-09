内存消耗 : 34.1 MB, 在所有 javascript 提交中击败了 100.00% 的用户

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    let digits = 1;
    let product = 1;
    let sum = 0;
    while(n !== 0){
        digits = n % 10;
        n = parseInt(n / 10);
        sum = sum + digits;
        product = product * digits;
    }
    return product - sum;
};
```