```
var countCharacters = function(words, chars) {
    // 先创建一个哈希表，记录可以用的字符和对应数量
    const charsMap = {}
    let res = 0
    for(let char of chars) {
        charsMap[char] ? charsMap[char]++ : (charsMap[char] = 1)
    }
    // 遍历每个单词，与哈希表进行比较，能拼写完成则累加单词长度
    for(let word of words) {
        const map = {...charsMap}
        let isComplete = true
        for (let w of word) {
            if (map[w] > 0) {
                map[w]--
                continue
            } else {
                isComplete = false
                break
            }
        }
        isComplete && (res += word.length)
    }
    return res
};
```