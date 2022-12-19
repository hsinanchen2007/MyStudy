### 解法一
word1和word2相同的情况单独处理，不同时，为何word1和word2的索引指针

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var shortestWordDistance = function(words, word1, word2) {
    const len = words.length
    let distance = Infinity
    if (word1 === word2) {
        const temp = []
        for (let i = 0; i < len; i++) {
            if (words[i] === word1) {
                if (temp.length) {
                    distance = Math.min(distance, Math.abs(i - temp[temp.length - 1]))
                }
                temp.push(i)
            }
        }
    } else {
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
    }
    return distance
};
```

### 解法二
将word1和word2相同与否一起考虑，不分类，具体看代码

### 代码
```javascript
/**
 * @param {string[]} words
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var shortestWordDistance = function(words, word1, word2) {
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
        } 
        // 这个if在word1和word2相等时，只是更新index2的索引
        if (words[i] === word2) {
            index2 = i
            // 这里只有index1 !== index2时才执行
            if (index1 >= 0 && index1 !== index2) {
                distance = Math.min(distance, Math.abs(index1 - index2))
            }
        }
    }
    return distance
};
```