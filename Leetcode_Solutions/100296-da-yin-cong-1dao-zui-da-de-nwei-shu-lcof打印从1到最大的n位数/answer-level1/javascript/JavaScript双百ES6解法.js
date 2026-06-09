
```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var printNumbers = function(n) {
    //return Array.from({length:10**n-1},(v, i) => i+1)
    return [...new Array(Math.pow(10,n)).keys()].slice(1)  
};
```