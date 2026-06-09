```javascript
var minimumLengthEncoding = function(words) {
    let wordSet = new Set(words);
    for (let word of wordSet) {
        for (let i = 1; i <= word.length; i++) {
            let frag = word.slice(i);
            wordSet.has(frag) && wordSet.delete(frag);
        }
    }
    return [...wordSet].reduce((sum, word) => sum + word.length + 1, 0);
};
```
数组首先转为 set 进行去重
循环每个单词进行切片
若集合中存在相同词尾则删掉该片段
过滤后的集合再利用 reduce 求和
单个单词由于存在结尾#长度还需+1