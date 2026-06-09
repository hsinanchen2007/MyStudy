题目很简单，记录字母出现的个数，偶数个直接加上
如果出现奇数，则加奇数-1，并在最后的答案上加 1
但是有个坑是，'z'.charCodeAt()是57，并不是 51，A-Z 和 a-z并不是连续的，所以最后遍历的时候不能用 52
```
var longestPalindrome = function (s) {
    var arr = []
    var judge = false
    var res = 0
    for (var i = 0; i < s.length; i++) {
        var num = s[i].charCodeAt() - 65
        arr[num] = arr[num] ? arr[num] + 1 : 1;
    }
    for (var j = 0; j < 58; j++) {
        var temp = arr[j]
        if (temp) {
            if (temp % 2 === 0) res += temp
            else {
                res += (temp - 1)
                judge = true
            }
        }
    }
    return judge ? res + 1 : res
};
```
