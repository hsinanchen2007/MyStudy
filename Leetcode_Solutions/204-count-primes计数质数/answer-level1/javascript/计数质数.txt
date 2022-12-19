*法一：直接循环判断每个数是否是质数*

缺点：超时

```js
var countPrimes = function(n) {
    var count = 0;
    for (let i = 1; i < n; i++) {
        if (isPrime(i)) {
            count++
        }
    }
    // 判断是否是质数
    function isPrime(k) {
        if (k === 1) {
            return false
        }
        for(let i = 2; i < k; i++) {
            if (Number.isInteger(k/i)) {
                return false
            }
        } 
        return true   
    }
    return count; 
};
```

*法二：厄拉多塞筛法*

每计算一个数，都要把它的倍数去掉。到了n，数一下留下了几个数。

```js
var countPrimes2 = function(n) {
    var count = 0;
    var arr = [];
    for (let i = 2; i < n; i++) {
        if (!arr[i]) {
            count++
            for (let j = 2 * i; j < n; j += i) {
                arr[j] = true
            }
        }
    }
    return count; 
};
```
