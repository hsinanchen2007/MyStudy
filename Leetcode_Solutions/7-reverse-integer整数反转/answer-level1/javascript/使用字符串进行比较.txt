```js
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    var
        xx = Math.abs(x),
        length = xx.toString().length,
        result = '';
    
    for(let i=0;i<length;i++){
        result += xx%10;
        xx=parseInt(xx/10);
    }
    // 判断位数，用字符串比较
     if(length >= 10 && ("2147483648"<=-result.toString() || result.toString()>="2147483647") ) {
         console.log(result)
        return 0;
    }
    return x<0?parseInt(result)*(-1) : parseInt(result)
};
```
