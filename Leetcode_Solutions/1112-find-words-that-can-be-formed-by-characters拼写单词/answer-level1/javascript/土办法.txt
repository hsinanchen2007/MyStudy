### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function (words, chars) {
    let charsArr = chars.split('');
    let ans = 0;
    for (let i = 0; i < words.length; i++) {
        let ca = [...charsArr];
        let current = -1;
        for (let j = 0; j < words[i].length; j++) {
            if (ca.indexOf(words[i][j]) > -1) {
                ca.splice(ca.indexOf(words[i][j]), 1)
                if (j === words[i].length - 1) {
                    ans += words[i].length;
                }
            } else {
                break;
            }
        }
    }
    return ans;
};
```