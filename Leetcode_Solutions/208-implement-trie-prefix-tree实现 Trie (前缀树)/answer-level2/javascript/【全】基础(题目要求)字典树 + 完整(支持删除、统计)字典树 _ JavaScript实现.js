
## 题目分析

本题的目的是实现一个字典树，这个字典树的主要功能就是 2 个：

-   存放单词
-   查找单词是否存在

## 代码实现

节点单独封装为一个类，它有两个属性：

-   next：`next[i]`保存着下一个字符`i`的节点引用
-   isEnd：当前节点是否可以作为一个单词的结束位置

可以看到，节点本身不存储字符，字符是保存在`next`对象中的 key 中。**直观来看，字符是保存在节点之间的连线上的**。

代码实现如下：

```javascript
// ac地址: https://leetcode-cn.com/problems/implement-trie-prefix-tree/
// 原文地址：https://xxoo521.com/2020-02-29-trie-prefix-tree/

var TrieNode = function() {
    this.next = {};
    this.isEnd = false;
};

/**
 * Initialize your data structure here.
 */
var Trie = function() {
    this.root = new TrieNode();
};

/**
 * Inserts a word into the trie.
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
    if (!word) return false;

    let node = this.root;
    for (let i = 0; i < word.length; ++i) {
        if (!node.next[word[i]]) {
            node.next[word[i]] = new TrieNode();
        }
        node = node.next[word[i]];
    }
    node.isEnd = true;
    return true;
};

/**
 * Returns if the word is in the trie.
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word) {
    if (!word) return false;

    let node = this.root;
    for (let i = 0; i < word.length; ++i) {
        if (node.next[word[i]]) {
            node = node.next[word[i]];
        } else {
            return false;
        }
    }
    return node.isEnd;
};

/**
 * Returns if there is any word in the trie that starts with the given prefix.
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function(prefix) {
    if (!prefix) return true;

    let node = this.root;
    for (let i = 0; i < prefix.length; ++i) {
        if (node.next[prefix[i]]) {
            node = node.next[prefix[i]];
        } else {
            return false;
        }
    }
    return true;
};
```

## 拓展思考：如何删除单词？

题目中的字典树的功能并不完整，它缺失 2 个重要功能：

-   删除单词
-   统计单词出现次数

为了解决这个问题，需要给每个 TrieNode 准备 2 个 number 类型变量：

-   path：代表从当前节点经过的单词数量
-   end：代表以当前节点为结束的单词数量

对于「统计单词次数」的功能，搜索完成后，读取最后结束节点的 end 即可。

对于「删除单词」的功能，依次在对路径上节点的 path 减 1。优化的地方是：当 path 为 0 时，说明没有单词经过了，不需要再向下遍历，直接移除以下所有节点即可。

篇幅原因，我把 JavaScript 实现的具有删除功能的 Trie 和测试用例放在了：[https://github.com/dongyuanxin/ciy/blob/master/algorithm/trie/better.js](https://github.com/dongyuanxin/ciy/blob/master/algorithm/trie/better.js)

## 更多资料

**若有错误，欢迎指正。若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer + Leetcode 题解](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
