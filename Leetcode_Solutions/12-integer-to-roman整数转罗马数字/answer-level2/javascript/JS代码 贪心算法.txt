```
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    var romanArr = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
    var arr = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    var str = ''

    for (var i = 0; i < 13;) {
        if (num >= arr[i]) {
            num -= arr[i]
            str += romanArr[i]
        } else {
            i++
        }
    }
    return str
};
```
