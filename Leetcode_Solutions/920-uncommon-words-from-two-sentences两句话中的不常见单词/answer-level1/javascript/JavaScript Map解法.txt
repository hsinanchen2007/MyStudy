### 解题思路
使用一个map统计两个句子中不同单词数，最终返回所有只出现1次的单词即可
![leetcode884.jpg](https://pic.leetcode-cn.com/a27c026528b9f6de97ebd99473e6b145a3b0e63977d38f574fcb52625432212b-leetcode884.jpg)


### 代码

```javascript
/**
 * @param {string} A
 * @param {string} B
 * @return {string[]}
 */
var uncommonFromSentences = function(A, B) {
    const aArr = A.split(' ')
    const bArr = B.split(' ')
    const aLen = aArr.length
    const bLen = bArr.length
    const map = new Map()
    const res = []
    if (aLen) {
        for (let i = 0; i < aLen; i++) {
            map.set(aArr[i], map.has(aArr[i]) ? map.get(aArr[i]) + 1 : 1)
        }
    }
    if (bLen) {
        for (let i = 0; i < bLen; i++) {
            map.set(bArr[i], map.has(bArr[i]) ? map.get(bArr[i]) + 1 : 1)
        }
    }
    map.forEach((value, word) => {
        if (map.get(word) === 1) {
            res.push(word)
        }
    })
    return res
};
```