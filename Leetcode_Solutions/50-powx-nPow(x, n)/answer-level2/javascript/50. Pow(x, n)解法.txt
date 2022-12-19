76 ms	33.8 MB
```
var myPow = function(x, n) {
    if(n == 0) return 1;
    if(n < 0) return 1/myPow(x,-n);
    if(n%2) return x*myPow(x,n-1);
    return myPow(x*x,n/2);
};
```
80 ms	33.7 MB
```
var myPow = function(x, n) {
    if(n < 0){
        x = 1/x;
        n = -n;
    }
    let pow = 1;
    while(n){
        if(n&1) pow*=x;
        x*=x;
        n>>>=1;
    }
    return pow;
};
```

