### 解题思路
感觉没啥奇技淫巧，成绩倒还行。执行用时100 ms，在所有 JavaScript 提交中击败了98.68%的用户，内存消耗40.9 MB，在所有 JavaScript 提交中击败了88.52%的用户。

平平无奇的解法，逐个去检查，找到一个就从chars里面删掉一个，words通过一个就加一个长度，复原chars，来下一个words.....
（另外，string不能用splice的吗？）

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function (words, chars) {
    if (words.length === 0 || chars.length === 0) {
        return 0;
    }

    let charsCopy = chars,
        idx = 0,
        len = 0;

    for (let i = 0; i < words.length; i++) {
        chars = charsCopy;

        if (words[i].length > chars.length) {
            continue;
        }

        eachWord: {
            for (let j = 0; j < words[i].length; j++) {
                idx = chars.indexOf(words[i][j]);
                if (idx != -1) {
                    // chars.splice(idx, 1);    <-- chars.splice is not a function
                    chars = chars.substring(0, idx) + chars.substring(idx + 1, chars.length);
                } else {
                    break eachWord;
                }
            }
            len += words[i].length;
        }
    }

    return len;
};
```