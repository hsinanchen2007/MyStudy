```
var countCharacters = function (words, chars) {
    // 26个字母代表每个下标
    let charCodeArr = Array(26).fill(0)
    for (let i = 0; i < chars.length; ++i) {
        // 转成ASCII码
        let code = chars.charCodeAt(i) - 97
        charCodeArr[code] = charCodeArr[code] + 1
    }
    let i = 0
    let len = words.length
    let num = 0
    while(i < len) {
        let word = words[i]
        // 当元素大于0的时候代表字母存在
        let has = true
        // 浅拷贝
        let newCharCodeArr = [...charCodeArr]
        for (let key of word) {
            let code = key.charCodeAt() - 97
            if (newCharCodeArr[code] === 0) {
                has = false
                break
            }
            // 使用一次，元素减一
            --newCharCodeArr[code]
        }
        if (has) {
            num += word.length
        }
        ++i
    }
    return num
}
```
