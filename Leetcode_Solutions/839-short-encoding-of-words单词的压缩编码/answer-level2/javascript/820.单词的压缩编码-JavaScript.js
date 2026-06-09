### 解题思路
删除公共后缀原则，可以考虑使用字典树

### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function(words) {
    let hashWords = new Set(words)
    for(let word of hashWords) {
        for (let i = 1; i < word.length; i++) {
            let tmp = word.slice(i);
            words.includes(tmp) && hashWords.delete(tmp)
        }
    }
    let result = 0;
    hashWords.forEach(v => result += v.length + 1)
    return result

};
```