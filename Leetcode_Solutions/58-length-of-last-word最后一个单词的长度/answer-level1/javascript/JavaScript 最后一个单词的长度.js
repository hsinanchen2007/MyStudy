解一：
> `split`将字符串风格成数组，然后对空格进行处理。

```js
var lengthOfLastWord = function(s) {
    var words = s.split(" ")
    while(words[words.length-1]==='') words.pop()
    if (words.length===0) return 0
    return words[words.length-1].length
};
```

解二：
> 思路和解一差不多，只是将处理空格的步骤放在最前面，并且使用了正则表达式。

```js
var lengthOfLastWord = function(s) {
    s = s.replace(/ *?$/g,'')
    var words = s.split(" ")
    return words[words.length-1].length
};
```