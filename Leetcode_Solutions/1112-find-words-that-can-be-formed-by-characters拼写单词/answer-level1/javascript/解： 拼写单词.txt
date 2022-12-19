### 解题思路

见注释

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function (words, chars) {
    return words.filter(/** 每个字母只能用一次,所以 word 一定比 chars 短 */ word => word.length <= chars.length).filter(word => {
        let c = chars

        for (let i = 0; i < word.length; i++) {
            let w_s = word[i]
            let c_i = c.indexOf(w_s)
            
            if (c_i === -1) {
                return false
            } else {
                /** w_s 这个字符用过一次就剔除一个 w_s 他的位置并不重要 */
                c = c.replace(w_s, '')
                continue
            }
        }
        return true
    /** 这里我一开始是直接返回的 words.length 审题不清，后来才发现是每个单词的长度之和 */
    }).join('').length
};
```