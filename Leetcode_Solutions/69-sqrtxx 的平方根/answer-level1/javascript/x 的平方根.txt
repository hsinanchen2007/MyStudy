*法一：推荐*
```js
var mySqrt = function(x) {
   return parseInt(Math.sqrt(x)) 
};

var x = 10;
console.log(mySqrt(x))
```

*法二：缺点：慢*
```js
var mySqrt2 = function(x) {
    var i = 0;
    while(!(i*i<=x && (i+1)*(i+1)>x)){
        i++;
    }
    return i
};
console.log(mySqrt2(x))
```

