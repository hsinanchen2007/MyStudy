### 解题思路
因为要求最短，在遍历单词的过程中，只需要与最近一次匹配到的值的索引进行计算即可

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var findClosest = function(words, word1, word2) {
    let distance = 9999
    let word1Index = -1
    let word2Index = -1
    for(let i = 0; i < words.length; i++) {
        if(words[i] === word1) {
            word1Index = i
            if(word2Index !== -1) {
                let d = word2Index - word1Index
                if(d < 0) {
                    d = -d
                }
                if(d<distance) {
                    distance = d
                }
            }
        } else if(words[i]=== word2) {
            word2Index = i
            if(word1Index !== -1) {
                let d = word2Index - word1Index
                if(d < 0) {
                    d = -d
                }
                if(d<distance) {
                    distance = d
                }
            }
        }
    }
    return distance
};
```