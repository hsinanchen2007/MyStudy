### 解题思路
常规解法，遍历一次字符串，记录当前的字符、字符数量

遇到相同字符，字符数量就相加
不同就替换当前字符，拼接前一次记录的字符、字符数量，且当前字符数量重置

### 常规解法代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    let res = '',
        cur = S[0],
        count = 0
    
    for (let i = 0; i < S.length; i++) {
        if (cur === S[i]) {
            count++
        } else {
            res += `${cur}${count}`
            cur = S[i]
            count = 1
        }
    }

    res += `${cur}${count}`

    return res.length >= S.length ? S : res
};
```

### 解题思路

首先，正则匹配当前遍历的字符
再则，把当前字符 和 匹配到的字符串长度拼接
最后，把 i 指向正则匹配后字符串后一位

只是一种骚操作，其实并没有什么用

### 正则解法代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    let res = ''

    for (let i = 0; i < S.length;) {
        // 切掉已遍历字符，再进行正则匹配
        let matchStr = S.slice(i).match(new RegExp(`${S[i]}+`))[0]
        
        res += `${S[i]}${matchStr.length}`
        // i 从当前正则匹配的字符后一位开始遍历
        i += matchStr.length
    }

    return res.length >= S.length ? S : res
};
```