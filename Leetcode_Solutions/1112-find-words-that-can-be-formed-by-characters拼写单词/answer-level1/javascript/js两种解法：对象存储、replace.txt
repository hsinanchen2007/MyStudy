### 解题思路

**对象存储**：用对象存储`chars`,匹配到该字母时，判断值
- 字母的值为`0`或`undefined`时，即该字母不能拼写，false
- 字母的值大于0时，其值-1

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function (words, chars) {
    let sum = 0
    let objS = {}
    for (i in chars) {
        objS[chars[i]] = (objS[chars[i]]) ? objS[chars[i]] + 1 : 1
    }
    for (i = 0; i < words.length; i++) {
        let obj = { ...objS }
        let isH = true
        for (j in words[i]) {
            if (obj[words[i][j]]) {
                obj[words[i][j]] -= 1
            } else {
                isH = false
                break
            }
        }
        isH ? sum += words[i].length : {}
    }
    return sum
};
```

**replace**：将每一个单词与`chars`比较，替换字母，如果替换前后的字符串相同，说明`chars`中没有该字母，false
```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function (words, chars) {
    let sum = 0
    for (i = 0; i < words.length; i++) {
        if (words[i].length <= chars.length) {
            let flag = true
            let str = chars
            for (j in words[i]) {
                let pStr = str
                str = str.replace(words[i][j], '')
                if (pStr === str) {
                    flag = false
                    break
                }
            }
            if(flag){
                sum += words[i].length
            }
        }
    }
    return sum
};

```