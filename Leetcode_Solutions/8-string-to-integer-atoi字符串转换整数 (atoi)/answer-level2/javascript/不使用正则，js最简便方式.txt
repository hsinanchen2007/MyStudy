```
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    let number= parseInt(str)
    if(isNaN(number))
        return 0
    if(number<-2147483648)
        return -2147483648
    if(number>2147483647)
        return 2147483647
    return number
};
```
