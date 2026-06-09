# 通过正则匹配可以很快的找到

字符串的match方法，可以通过正则匹配到所要的值，

返回第二个参数就是对应的index值；

```
haystack.match(new RegExp(needle)).index
```

# 代码如下：

```
var strStr = function(haystack, needle) {
    let res = haystack.match(new RegExp(needle))
    return res ? res.index : -1
};

```

