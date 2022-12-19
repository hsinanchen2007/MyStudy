### 代码
```javascript
/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    var first = 0;
    var second = 1;
    if(n == 0) return 0;
    if(n == 1) return 1
    var tmp;
    for(var i = 2; i <= n; i++){
        tmp = (first + second)%1000000007;
        first = second;
        second = tmp;
    }
    return tmp;
};
```