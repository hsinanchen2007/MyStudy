*法一*

```js
var findOcurrences = function(text, first, second) {
    let arr = text.split(/\s+/);
    let res = []
    for (let i = 0; i < arr.length-2; i++) {
        if (arr[i] == first && arr[i+1]) {
            res.push(arr[i+2])
        }
    }
    return res
};
```

*法二：正则*

```js
var findOcurrences = function(text, first, second) {
    let res = []
    let pat = new RegExp(`(?<=\\b${first}\\s+${second}\\s+)\\w+`, 'gm')
    let item;
    while((item = pat.exec(text)) !== null) {
        res.push(item[0])
    }
    return res
};
```

1. (?<=) 表示向左看，用字符串模板时需要转义`\\b` 、 `\\s` 、 `\\w`


2. `\b`[隐式位置](https://www.cnblogs.com/beiyi888/p/10281141.html)

如果不加 \b

例子 "aa good girl she is a good student"

会错误的匹配到 ["girl","student"]

而预期正确答案是 ["student"]


3. `修饰符m :` 表示执行多行匹配


