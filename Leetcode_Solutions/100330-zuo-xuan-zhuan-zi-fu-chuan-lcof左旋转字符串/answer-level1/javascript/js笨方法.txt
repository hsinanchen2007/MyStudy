js笨方法：

```
var reverseLeftWords = function(s, n) {
    return `${s.substr(n,s.length-1)}${s.substr(0, n)}`
};```
```
这是api(substring，concat之类不熟悉的写法)