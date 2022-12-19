### 解题思路
hash 表映射：
关键点有 4 个：
1. 每一个单词自身就是自己的相似值，即 words1 = ['i'] 和 words2 = ['i'] 无论pairs 有什么，他们都是相似的。
2. 相似的单词可以是多个，所以要做数组来存储。
3. 如果 pairs 是一个空数组（pairs.length === 0），返回 true
4. 如果两个单词数组长度不相等，返回 false

### 代码

```javascript
/**
 * @param {string[]} words1
 * @param {string[]} words2
 * @param {string[][]} pairs
 * @return {boolean}
 */
var areSentencesSimilar = function(words1, words2, pairs = []) {
    if(words1.length !== words2.length) return false
    if(pairs.length === 0) return true
    let hash = {}
    words1.forEach(ele => {
        if(!hash[ele]) hash[ele] = [ele]
        else hash[ele].push[ele]
    })
    words2.forEach(ele => {
        if(!hash[ele]) hash[ele] = [ele]
        else hash[ele].push[ele]
    })
    pairs.forEach(ele => {
        if(!hash[ele[1]]) hash[ele[1]] = [ele[1]]
        if(!hash[ele[0]]) hash[ele[0]] = [ele[0]]
        hash[ele[1]].push(ele[0])
        hash[ele[0]].push(ele[1])
    })
    for(let i = 0; i < words1.length; i++ ){
        if(!hash[words1[i]] && hash[words1[i]] !== 0) return false
        if(hash[words1[i]].indexOf(words2[i]) === -1) return false
    }
    return true
};
```