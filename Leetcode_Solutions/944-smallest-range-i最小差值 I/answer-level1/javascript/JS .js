```js
var smallestRangeI = function (A, K) {
           return (Math.max(...A)- K - Math.min(...A) - K) < 0 ? 0 : (Math.max(...A)- K - Math.min(...A) - K) 
        };
```