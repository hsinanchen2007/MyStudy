/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    var isNegative = x < 0, x = Math.abs(x);

    var reverseX = Number(String(x).split('').reverse().join(''));

    if (reverseX < Math.pow(-2, 31) || reverseX > (Math.pow(2, 31) - 1)) return 0;

    return isNegative ? -reverseX : reverseX;
};