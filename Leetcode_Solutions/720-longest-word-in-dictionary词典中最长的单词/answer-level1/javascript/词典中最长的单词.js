```js
var longestWord = function(words) {
    // 按照字典顺序排序 ["a", "ap", "app", "appl", "apple", "apply", "peer"]
    words.sort();
    let set = new Set();
    res = '';
    for(let item of words) {
        if(item.length == 1 || set.has(item.substring(0, item.length - 1))) {
            // 预防长度一定时， 后面的'apply' 会覆盖前面的 'apple'
            res = item.length > res.length ? item : res;
            set.add(item);
        }
    }
    return res
};
```

