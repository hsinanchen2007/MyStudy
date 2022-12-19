### 解题思路

循环通过Indexof判断，存储

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    const result = [], arr = chars.split('')
    let temp = [], flag = true
    for (let i = 0; i < words.length; i++) {
        temp = [...arr]
        flag = true
        for (j = 0; j < words[i].length; j++) {
            let index = temp.indexOf(words[i][j])
            if (index === -1) { // 不存在
                flag = false
                break
            } else { // 存在
                temp.splice(index, 1)
            }
        }
        if (flag) result.push(words[i])
    }
    if (!result.length) return 0
    let res = 0
    for (let i = 0; i < result.length; i++) {
        res += result[i].length
    }
    return res
};
```