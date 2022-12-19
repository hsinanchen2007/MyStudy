使用二分查找，log(2^31) = 31次，最多查找31次就可以找到
```
/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var divide = function(dividend, divisor) {
    let isForward = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? true : false;  
    var absDividend = dividend > 0 ? dividend : -dividend;
    var absDivisor = divisor > 0 ? divisor : -divisor;
 
    var left = 0;
    var right = isForward ? 2147483647 : 2147483648;
    var result = left;
    while(left <= right){
        middle = Math.floor((left + right) / 2);
        if(middle * absDivisor == absDividend){
            result = middle;
            break;
        }else if(middle * absDivisor > absDividend){
            right = middle - 1;     
        }else{
            result = middle;
            left = middle + 1;
        }
    }
    result = isForward ? result : -result;
    return result;
};
```
