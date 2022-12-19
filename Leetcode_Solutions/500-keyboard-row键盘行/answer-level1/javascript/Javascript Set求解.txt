### 解题思路
因为是求在“在不在”的问题，所以使用Set

### 代码

```javascript
/**
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(words) {
    const len = words.length
    const res = []
    if (!len) {
        return res
    }
    // 初始化set保存键盘每一行的信息
    const first = new Set(['Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'])
    const second = new Set(['A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'])
    const third = new Set(['Z', 'X', 'C', 'V', 'B', 'N', 'M'])
    for (let i = 0; i < len; i++) {
        const word = words[i]
        const wLen = word.length
        const char = word[0].toUpperCase()
        let inSameLine = true
        // 用单词第一个字母确定它应该是第几行
        let line = first
        if (second.has(char)) {
            line = second
        } else if (third.has(char)) {
            line = third
        }
        for (let j = 1; j < wLen; j++) {
            // 发现不在该行的字母，则这个单词不在最终返回
            if (!line.has(word[j].toUpperCase())) {
                inSameLine = false
            }
        }
        if (inSameLine) {
            res.push(word)
        }
    }
    return res
};
```