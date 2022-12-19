用正则表达式很好解决，由于这里正则表达式需要匹配变量，所以只能用构造函数 `new RegExp` 的形式；
使用 `RegExp`对象的 `exec()`方法检测字符串，有一个好处就是可以直接利用它的 `index` 属性。
`exec()`方法返回一个包含匹配项的数组，如果没有匹配项就返回 `null`，同时它还具有两个额外的属性：
    - `index`：匹配项在`exec()`参数字符串中的位置；
    - `input`: 参数字符串。
```javascript []
var strStr = function(haystack, needle) {
    if(needle === '') {
        return 0;
    }
    let reg = new RegExp(needle);
    let res = reg.exec(haystack);
    if(res) {
        return res.index;
    }
    return -1;
};
```


