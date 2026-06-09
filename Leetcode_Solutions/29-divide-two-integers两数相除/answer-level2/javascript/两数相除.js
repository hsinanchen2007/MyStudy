参考一位大佬的想法，一步步逼近结果:
举个例子：11 除以 3 :
首先11比3大，结果至少是1， 让3翻倍，就是6，发现11比3翻倍后还要大，那结果就至少是2了，再这个6再翻倍，得12，11小于12。那结果肯定在2和4之间。也就是说2再加上某个数，这个数是多少呢？让11减去刚才最后一次的结果6，剩下5，我们计算5是3的几倍。照着这样循环，直到出现被除数小于除数除的时候，返回0.
```javascript
/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var divide = function(dividend, divisor) {
    var INT_MAX = Math.pow(2, 31) - 1;
    var INT_MIN = Math.pow(-2, 31);
    if (dividend == 0) return 0;
    if (divisor == 1) return dividend;
    if (divisor == -1) {
        if(dividend > INT_MIN) return -dividend;
        return INT_MAX;
    }

    var a = dividend;
    var b = divisor;
    var sign = 1; 
    if((a > 0 && b < 0) || (a < 0 && b > 0)){
        sign = -1;
    }
    a = a > 0 ? a : -a;
    b = b > 0 ? b :-b;
    var res = div(a,b);

    if(sign > 0) return res > INT_MAX ? INT_MAX : res;
    return -res;

    function div(a, b) {
        if (a < b) return 0;
        var count = 1;
        var tb = b;

        while ((tb + tb) <= a) {
            count = count + count;
            tb = tb + tb;
        }

        return count + div(a - tb, b);
    }
};
```