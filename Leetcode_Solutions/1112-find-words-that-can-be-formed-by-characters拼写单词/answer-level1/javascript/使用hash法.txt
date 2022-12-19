### 解题思路
根据题目我们知道的信息有：每次拼写时，chars中的每个字母只能使用一次， 用chars中的字符拼写出words中某个单词，就认为掌握了这个单词。
也就是说只要words中某个单词中的字母出现次数不超过chars中每个字母出现的次数，就算掌握了。
基于上面的思路，我们可以使用hash表来存储chars中每个字母出现的次数，以key-value的形式储存。
遍历单词表中的每个单词，然后使用上面生成的hash表去查找存不存在这个字母，存在就减去1次，如果最后是负数 就不符合条件。
最后将长度相加，就是我们要的答案。

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    let charsMap = new Map()
    let res = 0

    for (let s of chars) {
        charsMap.set(s, charsMap.has(s) ? charsMap.get(s) + 1 : 1)
    }

    for (let w of words) {
        if (help(w, new Map(charsMap))) {
            res += w.length
        }
    }
    return res
};

function help(w, hash) {
    for (let i of w) {
        if (!hash.has(i)) {
            return false
        } else {
            hash.set(i, hash.get(i) - 1)
            if (hash.get(i) < 0) {
                return false
            }
        }
    }
    return true
}

```