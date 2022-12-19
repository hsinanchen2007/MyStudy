```
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    if(x==0) return 0;
    if(x<(Math.pow(-2, 31)) || x>(Math.pow(2, 31)-1)) return 0;
    // console.log(-2^31)
    let flag = true
    if(x<0) {
        x * -1
        flag = false
    }
    let result = parseInt(x.toString().split("").reverse().join(""))
    if(result<(Math.pow(-2, 31)) || result>(Math.pow(2, 31)-1)) return 0;
    if(flag === false) return result*-1
    return result
};
```