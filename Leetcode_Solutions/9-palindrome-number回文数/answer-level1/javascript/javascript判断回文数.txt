计算与判断方式会比较粗暴一些
通过reverse来颠倒数组，从而重新排列数组，最后通过数组的值来与输入的值来进行判断值是否相等

var isPalindrome = function (x) {
    let numString = x + '';
    let numArr = numString.split("").reverse();
    let result = [];
    if (parseInt(x) < 0 || typeof x !== 'number') {
        return false;
    }

    for (let i = 0, len = numArr.length; i < len; i++) {
        result.push(numArr[i]);
    }
    result = parseInt(result.join(""));
    if (result != x) return false;
    
    return result == x;

};

isPalindrome(10);