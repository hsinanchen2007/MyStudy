思路就是转成字符串，再把字符串翻转后和翻转之前的字符串比较一下，如果相等就是回文数了


```
var isPalindrome = function(x) {
     var s1 = x.toString()
     var arr = s1.split('')
        arr.reverse()
    var s2 = arr.join('')
    return s2 == s1
};
```
