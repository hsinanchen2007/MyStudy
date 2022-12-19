### 解题思路

- 再添加时利用 `map` 数据结构将单词按长度进行分类；在查找时只查找对应长度下的单词。
- 将 `.` 替换为 `[a-z]` 利用正则去匹配。

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var WordDictionary = function() {
    this.wordDictionary = new Map();
};

/**
 * Adds a word into the data structure. 
 * @param {string} word
 * @return {void}
 */
WordDictionary.prototype.addWord = function(word) {
    const { length } = word;
    if(this.wordDictionary.has(length)){
        let wordArr = this.wordDictionary.get(length);
        wordArr.push(word);
        this.wordDictionary.set(length, wordArr);
    }else{
        this.wordDictionary.set(length, [word]);
    }
};

/**
 * Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. 
 * @param {string} word
 * @return {boolean}
 */
WordDictionary.prototype.search = function(word) {
    let wordArr = this.wordDictionary.get(word.length);
    if(!wordArr) return false;
    if(word.includes('.')){
        let wordReg = word.replace('\.','[a-z]');
        for(let i of wordArr){
            if(i.match(new RegExp(word))) return true;
        }
        return false;
    }
    return wordArr.includes(word);
};

/** 
 * Your WordDictionary object will be instantiated and called as such:
 * var obj = new WordDictionary()
 * obj.addWord(word)
 * var param_2 = obj.search(word)
 */
```