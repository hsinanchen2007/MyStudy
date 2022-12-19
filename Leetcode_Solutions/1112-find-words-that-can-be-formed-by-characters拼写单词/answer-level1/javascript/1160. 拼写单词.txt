### 解题思路


### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function (words, chars) {
    let charMap = {}
    for (let i = 0; i < chars.length; i++) {
        if (charMap[chars[i]]) {
            charMap[chars[i]]++
        } else {
            charMap[chars[i]] = 1
        }
    }

    let result = 0
    words.forEach(word => {
        let wordMap = { ...charMap }, flag = true
        for (let i = 0; i < word.length; i++) {
            if (wordMap[word[i]]) {
                wordMap[word[i]]--
            } else {
                flag = false
                break
            }
        }
        if (flag) {
            result += word.length
        }
    })
    return result
};
```