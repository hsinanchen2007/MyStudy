
那为什么这题我们要用字典树做呢？因为我们需要知道单词列表里，哪些单词是其它某个单词的后缀。既然要求的是后缀，我们只要把单词的倒序插入字典树，再用字典树判断某个单词的逆序是否出现在字典树里就可以了。

比如示例中的["time", "me", "bell"]的逆序就是["emit", "em", "lleb"]。我们可以发现em是emit的前缀。所以"em"就可以忽略了。我们必须要先插入单词长的数组，否则会有问题。比如如果我先插入了"em"，再插入"emit",会发现两个都可以插入进去，很显然是不对的，所以在插入之前需要先根据单词的长度由长到短排序。


### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function(words) {
    words.sort((a, b) => {
        return b.length - a.length;
    })
    let num = 0;
    const trie = new Trie();
    for (let i = 0; i < words.length; i++) {
        num += trie.insert(words[i]);
    }
    return num;
};

var Trie = function() {
    this.children = new Array(26);
};

Trie.prototype.insert = function(word) {
    let root = this;
    let isNew = false;
    for (let len = word.length, i = len - 1; i >= 0; i--) {
        const code = word.charCodeAt(i) - 97;
        if (!root.children[code]) {
            isNew = true;
            root.children[code] = new Trie();
        }
        root = root.children[code];
    }
    return isNew ? (word.length + 1) : 0;
};
```