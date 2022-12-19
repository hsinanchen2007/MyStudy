![image.png](https://pic.leetcode-cn.com/203bc97552d7d6446a68724a20ca01bfa179c4a61c39bdc1e8bd4369185c0085-image.png)

```
/**
 * @param {string} S
 * @param {string[]} words
 * @return {number}
 */
var expressiveWords = function(S, words) {
    let map = new Map()
    let count = 0
    const fn = (str) => {
        let len = str.length
        let wordStr = '', wordCount = [0]
        for(let i = 0; i < len; i++) {
            let lastWord = wordStr.slice(-1)
            if(str[i] !== lastWord) {
                wordStr += str[i]
                wordCount.push(1)
            } else {
                wordCount[wordCount.length - 1] += 1
            }
        }
        wordCount = wordCount.filter((i) => i !== 0)
        return {wordStr, wordCount}
    }
    const {
        wordStr,
        wordCount
    } = fn(S)
    
    for(let i of words) {
        let {
            wordStr: str = '',
            wordCount: itemCount = []
        } = fn(i)
        if (str !== wordStr) continue
        let right = 0
        let wordCountLen = wordCount.length
        for(let j = 0; j < wordCountLen; j++) {
            let num1 = wordCount[j]
            let num2 = itemCount[j]
            if (num1 > 2 && num2 <= num1 || num1 <= 2 && num1 === num2) right++
        }
        if (right === wordCountLen) count++
    }
    return count
};
```

