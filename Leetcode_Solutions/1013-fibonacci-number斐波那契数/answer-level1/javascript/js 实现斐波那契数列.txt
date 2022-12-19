```
/**
 * @param {number} N
 * @return {number}
 */
var fib = function(N,act1=0,act2=1) {
    if(N<1) return act1;
    return fib(N-1,act2,act1+act2)
};
```
