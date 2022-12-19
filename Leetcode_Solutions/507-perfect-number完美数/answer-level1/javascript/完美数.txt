```js
var checkPerfectNumber = function(num) {
    if (num === 1) return false;
    let res = 0;
    let middle = parseInt(Math.sqrt(num));
    while(middle > 1) {
        if (num % middle === 0) {
        	res += middle + num/middle;
        }
        middle--;
    }
    return res + 1 === num
};
```

