解决思路：

**确认一下几个基本条件**
    1. 最小有效括号对 一定是 (), [], {} 之一
    2. 一个**合法的** 括号字符串，在取出 最小有效括号对 之后，一定仍然是有效的合法括号字符串
    3. 逐步去除所有 最小有效括号对之后，合法的括号字符串长度会是 0

```
function isValid (str) {
    const reg = /\(\)|\{\}|\[\]/g
    // 记录之前字符串的长度， 当替换之后长度未变，则说明已经替换完毕
    let len = null
    while (len !== str.length) {
        len = s.length
        s = s.replace(reg, '')
    }
    return s.length === 0
}
```

Over~
