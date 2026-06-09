先从最大的开始比较，如果大于当前数，则res加入此数对应的罗马数，并将num减去当前数，循环，直到num小于当前数，进行下一个数的比较
var intToRoman = function(num) {
    let romans = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I'],
        nums = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9,  5, 4, 1],
        res = '',
        i = 0

    while (i < 13 || num > 0) {
        if (num >= nums[i]) {
            res += romans[i]
            num -= nums[i]
        }
        if (num < nums[i]) i++
    }
    return res
};