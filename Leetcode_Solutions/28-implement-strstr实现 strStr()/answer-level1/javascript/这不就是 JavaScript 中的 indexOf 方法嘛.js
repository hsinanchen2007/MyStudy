JavaScript 中有三个字符串方法都可以实现这个功能，分别是 indexOf , search, match

**indexOf 是最切合要求的，原本就是题目中要求的功能：**

```
var strStr = function(haystack, needle) {
    return haystack.indexOf(needle);
};

```

**search 方法与 indexOf 方法功能基本一样，只是search支持正则作为参数，则indexOf不支持**

```
var strStr = function(haystack, needle) {
    return haystack.search(needle);
};
```

match 方法返回一个结果数组，在没有指定正则修饰符g的时候，会额外提供index属性来表示位置，只是如果没有查找到，match返回的值为null。
```
var strStr = function(haystack, needle) {
    let ret = haystack.match(needle);
    return ret === null ? -1 : ret.index;
};
```