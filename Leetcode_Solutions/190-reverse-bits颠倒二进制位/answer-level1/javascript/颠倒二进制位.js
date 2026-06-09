借助数组的reverse()方法
```js
/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var reverseBits = function(n) {
    var temp = n.toString(2).padStart(32,0).split('').reverse().join('');
    return Number.parseInt(temp,2);
};
var n = 00000010100101000001111010011100;
console.log(reverseBits(n))
```