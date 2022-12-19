使用正则匹配所有单词，取最后一个的长度即可

``` javascript
function getLastWord(s) {
    const arr = s.macth(/\b\S+?\b/g);
    return arr ? arr.pop().length : 0;
}
```
