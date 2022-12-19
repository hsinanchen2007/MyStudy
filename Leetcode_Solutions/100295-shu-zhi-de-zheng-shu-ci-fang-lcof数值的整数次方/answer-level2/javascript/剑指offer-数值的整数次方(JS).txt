```js
var myPow = function(x, n) {
    // return Math.pow(x, n); 作弊写法
    
    if(n == 0) return 1;
    if(n < 0) return 1 / myPow(x, -n);
    if(n % 2) return x * myPow(x, n-1);
    return myPow(x * x, n/2);
};
```