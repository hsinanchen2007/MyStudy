### 解题思路
初次看到题目的时候，直接想到了暴力解法。
直接将每个word中的字母与chars中的字母去进行对比。（遍历每个word）。

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function (words, chars) {
    let charArr = chars.split("");
    let result = 0;
    for (let i = 0; i < words.length; i++) {
        //之后的splice修改了原数组，这里还原回去
        charArr = chars.split("");
        if(words[i].length>charArr.length) continue;
        for (var j = 0; j < words[i].length; j++) {
            let position = charArr.indexOf(words[i].charAt(j));
            if (position != -1) {
                charArr.splice(position, 1);
            } else {
                break;
            }
        }
        if (j == words[i].length)
            result += words[i].length;
    }
    return result;
};


```

