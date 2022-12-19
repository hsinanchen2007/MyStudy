# 我这可能是最短的代码，当然效率肯定不高。
利用JavaScript的JSON.stringify方法，把两个树都转换成json字符串，然后就是字符串与子字符串的事情了。。。
```
var isSubtree = function(s, t) {
    return JSON.stringify(s).includes(JSON.stringify(t));
};
```
