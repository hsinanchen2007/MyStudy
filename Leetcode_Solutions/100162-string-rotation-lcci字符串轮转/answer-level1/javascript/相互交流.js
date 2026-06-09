1.将第二个字符串拼接；
2.使用indexOf在第二个字符串中找第一个字符串；

```
var isFlipedString = function (s1, s2) {
    if (s1.length === 0 && s2.length === 0) {
        return true;
    }
    if (s1.length !== s2.length) {
        return false;
    }

    return (s2 + s2).indexOf(s1) >= 0 ? true : false;
};
```
