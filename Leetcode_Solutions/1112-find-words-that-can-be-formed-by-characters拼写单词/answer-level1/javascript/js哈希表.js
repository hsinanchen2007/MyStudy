### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    if (!words || !words.length || !chars || !chars.length) return 0;
    let origin = {}, res = 0;
    for (let i = 0; i < chars.length; i++) {
        if (origin[chars[i]]) {
            origin[chars[i]]++
        } else {
            origin[chars[i]] = 1;
        }
    }
    for (let i = 0; i < words.length; i++) {
        let copy = Object.assign({}, origin);
        for (let j = 0; j < words[i].length; j++) {
            if (chars.length < words[i].length) continue;
            if (copy[words[i][j]] && copy[words[i][j]] > 0) {
                copy[words[i][j]]--;
                if (j === words[i].length - 1) {
                    res += words[i].length;
                }
            } else {
                break;
            }
        }
    }
    return res;
};
```