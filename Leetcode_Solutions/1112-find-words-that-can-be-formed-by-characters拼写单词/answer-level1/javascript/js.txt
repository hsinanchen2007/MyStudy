### 解题思路
匹配成功就修改标识数组对应值

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    let count = 0;

    for (let i = 0; i < words.length; i ++) {
        let zd = chars.split('');
        for (let j = 0; j < words[i].length; j ++) {
            if (zd.indexOf(words[i][j]) != -1) {
                zd[zd.indexOf(words[i][j])] = ""

                if (j == words[i].length - 1) {
                    count += words[i].length;
                }
            } else {
                break;
            }
        }
    }

    return count
};
```