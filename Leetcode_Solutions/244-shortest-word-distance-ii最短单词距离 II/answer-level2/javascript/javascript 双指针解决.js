### 解题思路
使用index1，index2分别维护word1，word2出现的索引，一次循环解决

### 代码

```javascript
/**
* @param {string[]} words
*/
var WordDistance = function(words) {
    this.list = words
};

/** 
* @param {string} word1 
* @param {string} word2
* @return {number}
*/
WordDistance.prototype.shortest = function(word1, word2) {
    const len = this.list.length
    let distance = Infinity
    let index1 = -1
    let index2 = -1
    for (let i = 0; i < len; i++) {
        if (this.list[i] === word1) {
            index1 = i
            if (index2 >= 0) {
                distance = Math.min(distance, Math.abs(index1 - index2))
            }
        } else if (this.list[i] === word2) {
            index2 = i
            if (index1 >= 0) {
                distance = Math.min(distance, Math.abs(index1 - index2))
            }
        }
    }
    return distance
};

/** 
* Your WordDistance object will be instantiated and called as such:
* var obj = new WordDistance(words)
* var param_1 = obj.shortest(word1,word2)
*/
```