### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if (n === 0){
        return 1
    }
    if (n < 0){
        return 1 / myPow(x, -n)
    }
    if (n % 2){
        return x * myPow(x , n - 1);
    }
    return myPow(x * x, n / 2);
};
```
用分治的办法，将x^n次方划分为x^(n/2) * x^(n/2),每次划分一半下去。直到n === 1，这之间的过程我们可以用递归进行实现，而边境的判断条件就是当n===0时。
时间复杂度分析，因为我们每次都是x(n/2) * x ^ (n / 4) * x ^ (n / 8) * ... * 1;
所以我们的时间复杂度为o(log n);