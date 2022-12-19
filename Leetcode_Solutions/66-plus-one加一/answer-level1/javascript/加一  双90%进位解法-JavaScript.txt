/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    let len = digits.length;
    // 最后一位加1
    digits[len - 1] = digits[len - 1] + 1;
    for(let i = len - 1; i >= 1; i-- ) {
        //逢10向前进位
        if (digits[i] === 10) {
            digits[i] = 0;
            digits[i - 1] = digits[i - 1] + 1;
        }
    }
    //首位单独处理
    if (digits[0] === 10) {
        digits[0] = 0;
        digits.unshift(1);
    }
    return digits;
};