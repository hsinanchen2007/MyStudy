
## 题目分析

看到题目，第一个直觉是将单词都存放在数组中。每次匹配的时候，循环遍历数组，查看是否存在可以匹配的字符串。

但是这种暴力法的时间复杂度高，在平台上无法 ac。因此要想其他的方法。

## 解法 1: 巧妙的正则表达式

有一种非常巧妙的正则表达式方法：所有的单词不再存放在数组中，**而是通过前后添加“#”来进行分割（标识单词界限）**。

例如依次添加了“bad”、“mad”。那么内部字符串是：“#bad#mad#”。当我们要匹配目标串“.ad”时，只需要在目标串前后添加“#”即可。

在 leetcode 上，本题的 js 写法无法 ac，但是 python3 的可以。应该是判定条件比较宽松，下面的代码 ac 花费了 2924ms。

```python
# ac地址: https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/
# 原文地址：https://xxoo521.com/2020-02-29-add-and-search-word/

from re import search

class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.words = '#'


    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        self.words += (word + '#')

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        return bool(search('#' + word + '#', self.words))
```

## 解法 2: 字典树（Trie）+ DFS

对于记录/查找单词的情景，有种数据结构非常高效：Trie。我们可以构造一棵字典树，每次调用 addWord 时候，将单词存入字典树。

注意：当调用 search 进行查找的时候，如果当前字符不是`.`，那么就按照字典树的查找逻辑；否则，由于是通配符，要遍历当前的节点的 next 中的所有字符，这个过程和 DFS 一样。

代码如下：

```javascript
// ac地址: https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/
// 原文地址：https://xxoo521.com/2020-02-29-add-and-search-word/

var TrieNode = function() {
    this.next = {};
    this.isEnd = false;
};

/**
 * Initialize your data structure here.
 */
var WordDictionary = function() {
    this.root = new TrieNode();
};

/**
 * @param {string} word
 * @return {void}
 */
WordDictionary.prototype.addWord = function(word) {
    if (!word.length) return;

    let node = this.root;
    for (let i = 0; i < word.length; ++i) {
        if (!node.next[word[i]]) {
            node.next[word[i]] = new TrieNode();
        }
        node = node.next[word[i]];
    }
    node.isEnd = true;
};

/**
 * @param {string} word
 * @return {boolean}
 */
WordDictionary.prototype.search = function(word) {
    if (!word.length) return false;

    return this.dfs(this.root, word);
};

/**
 * @param {TrieNode} root
 * @param {string} word
 * @return {boolean}
 */
WordDictionary.prototype.dfs = function(root, word) {
    const length = word.length;
    let node = root;
    for (let i = 0; i < length; ++i) {
        const ch = word[i];
        // 若是通配符，则尝试遍历所有的情况(DFS)
        if (ch === ".") {
            const keys = Reflect.ownKeys(node.next);
            for (const key of keys) {
                const found = this.dfs(node.next[key], word.slice(i + 1));
                if (found) return true;
            }
            return false;
        }

        if (!node.next[ch]) {
            return false;
        }
        node = node.next[ch];
    }
    return node.isEnd;
};
```

## 更多资料

**若有纰漏，欢迎指正。若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer + Leetcode 题解](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
