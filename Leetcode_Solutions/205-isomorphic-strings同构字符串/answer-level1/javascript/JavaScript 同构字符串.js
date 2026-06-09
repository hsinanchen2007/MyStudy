解一：
> 用哈希表映射。
> 
> 由于JavaScript不能直接像操作数组一样操作字符串，所以前后还要加上`split`和`join`。此外，JavaScript也无法用`in`来判断元素是否存在于数组中，所以使用了两个哈希表。空间复杂度也就上升为两倍。当然也可以用一个哈希表和`indexOf`，但是经过测试时间和空间消耗都增加了不少。

```js
var isIsomorphic = function(s, t) {
    s = s.split('');
    t = t.split('');
    var len = s.length;
    var map = {};
    var checkbox = {};
    for (var i=0; i<len; i++){
        if (map[s[i]]!=null) s[i] = map[s[i]];
        else {
            if (checkbox[t[i]]) return false;
            map[s[i]] = t[i];
            checkbox[t[i]] = 1;
            s[i] = t[i];
        }
    }

    s = s.join('');
    t = t.join('');

    return s===t

};
```

解二：
> 对s和t同时遍历，查找当前字符第一次出现的位置，若位置不相等则返回`false`。
> 
> 这个方法的优点是不涉及额外的空间，也不需要进行真正的字符替换。因此时间复杂度和空间复杂度都非常低。

```js
var isIsomorphic = function(s, t) {
    for(var i = 0; i< s.length; i++) {
        if(s.indexOf(s[i]) !== t.indexOf(t[i]))
            return false
    }
    return true;
};
```

![](https://pic.leetcode-cn.com/d259924cdb98f0bb7a181747b390b7e422f24d415a68904f69895092d928c900-file_1570614600500)
