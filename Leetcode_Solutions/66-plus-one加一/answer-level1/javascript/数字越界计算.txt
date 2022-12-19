  这种数字越界题目 BigInt无敌, 无数字上限

var plusOne = function(digits) {
    return BigInt(BigInt(digits.join('')) + 1n).toString().split('')
};