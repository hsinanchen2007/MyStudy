*法一：字符串现成的indexOf()方法*
```js
var strStr = function(haystack, needle) {
    return haystack.indexOf(needle)
};

var haystack = "hello";
var needle = "ll";
console.log(strStr(haystack, needle))
```

*法二：借鉴字符串的substr方法*
```js
var strStr2 = function(haystack, needle) {
    var len = haystack.length;
    var needleLen = needle.length;
    if (needle === '') {
        return 0;
    }
    for (var i = 0; i < len; i++) {
        if (haystack[i] === needle[0]) {
            if (haystack.substr(i,needleLen) === needle) {
                return i;
            }
        }
    }
    return -1;
};

console.log(strStr2(haystack, needle))
```
