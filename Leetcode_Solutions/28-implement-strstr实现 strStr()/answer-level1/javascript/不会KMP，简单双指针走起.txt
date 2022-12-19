```
var strStr = function (haystack, needle) {
    if (needle.length == 0) return 0;
    let j = 0;
    for (let i = 0; i < haystack.length; i++) {
        if (haystack[i] == needle[j]) {
            j++;
            if (j == needle.length) return i - j + 1;
        }
        else {
            i = i - j;
            j = 0;
        }
    }
    return -1;
};
```