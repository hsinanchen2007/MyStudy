在一个for循环内完成: for(var i=0,a=0,b=1,c=1;i<N;c=a+b,a=b,b=c,i++) ;
```js
var fib = function(N) {
    for(var i=0,a=0,b=1,c=1;i<N;c=a+b,a=b,b=c,i++) ;
    return a;
};
```