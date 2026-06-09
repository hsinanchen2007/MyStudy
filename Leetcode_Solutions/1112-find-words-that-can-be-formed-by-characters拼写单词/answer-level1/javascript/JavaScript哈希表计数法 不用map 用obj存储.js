### 解题思路
只需判断chars中字母出现的次数>= words中单词的字母次数，即可认为掌握了该单词

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    let sum = 0;
    let charsObj = {};
    const contained = (chars, word) => {
        for (const char in word) {
            if (chars[char]) {
                if (chars[char] < word[char])
                    return false;
            } else {
                return false;
            }
        }
        return true;
    } 
    for (const char of chars) {
        let val = charsObj[char];
        charsObj[char] = val ? val + 1 : 1;  
    }
    words.forEach(word => {
        let wordObj = {};
        for (const char of word) {
            let val = wordObj[char];
            wordObj[char] = val ? val + 1 : 1;  
        }
        if (contained(charsObj, wordObj)) sum += word.length;
    });
    return sum;
};
```