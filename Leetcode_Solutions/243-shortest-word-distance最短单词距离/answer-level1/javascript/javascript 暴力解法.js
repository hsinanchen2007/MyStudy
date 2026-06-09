### 解法一
两重循环，效率低

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var shortestDistance = function(words, word1, word2) {
    const len = words.length
    let distance = Infinity
    for (let i = 0; i < len; i++) {
        if (words[i] === word1) {
            for (let j = 0; j < len; j++) {
                if (words[j] === word2) {
                    distance = Math.min(distance, Math.abs(i - j))
                }
            }
        }
    }
    return distance
};
```

### 解法二
使用两个指针分别记录word1,word2出现索引，只需要一次循环

### 代码
```javascrip
/**
 * @param {string[]} words
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var shortestDistance = function(words, word1, word2) {
    const len = words.length
    let distance = Infinity
    let index1 = -1
    let index2 = -1
    for (let i = 0; i < len; i++) {
        if (words[i] === word1) {
            index1 = i
            if (index2 >= 0) {
                distance = Math.min(distance, Math.abs(index1 - index2))
            }
        } else if (words[i] === word2) {
            index2 = i
            if (index1 >= 0) {
                distance = Math.min(distance, Math.abs(index1 - index2))
            }
        }
    }
    return distance
};
```