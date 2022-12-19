js 纯数学7行
```js
var findNthDigit = function(n) {
    if (n < 10) return n;
    let sum = 10, i = 1;
    while(n > sum) {
        n -= sum;
        sum = 9 * Math.pow(10, i) * ++i;
    }
    return (sum / 9 / i + parseInt(n / i) + '')[n % i];
}
```
