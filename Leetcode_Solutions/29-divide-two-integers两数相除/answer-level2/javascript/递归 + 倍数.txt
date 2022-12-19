### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var INT_MAX = Math.pow(2, 31) - 1;
var INT_MIN = Math.pow(-2, 31);
var divide = function(dividend, divisor) {
    if (dividend == 0) return 0;
    if (divisor == 1) return dividend;
    if (divisor == -1) {
        if(dividend > INT_MIN) return -dividend; // 只要不是最小的那个整数，都是直接返回相反数就好啦
        return INT_MAX;// 是最小的那个，那就返回最大的整数啦
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