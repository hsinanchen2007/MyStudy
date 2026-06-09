```js
var fib = function(n) {
    let arr = [0, 1];
    for(let i = 2; i <= n; i++){
        arr.push(arr[i-1]% 1000000007 + arr[i-2]% 1000000007);
    }
    return arr[n] % 1000000007;
};
```