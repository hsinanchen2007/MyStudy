```
var isPalindrome = function(x) {
    // 小于 10 的正整数均为回文数，多一个这个判断，可以少执行一层 while 循环
    if (x >= 0 && x <= 9) {
        return true
    }
    if (x < 0 || x % 10 === 0) {
        return false
    }
    let start = x;
    let end = 0;
    while(start > 0) {
        end = start % 10 + end * 10;
        start = ~~(start / 10); // 对于浮点数，~~value可以代替parseInt(value)，而且前者效率更高些
    }
    return end === x
};
```
