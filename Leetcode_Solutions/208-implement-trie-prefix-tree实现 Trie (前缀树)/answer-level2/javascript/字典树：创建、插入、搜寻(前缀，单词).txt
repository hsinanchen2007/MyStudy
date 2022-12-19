## 创建一个基本的 字典树步骤
此处撰写基本概念
### 什么是字典树
  字典树又叫前缀树、单词查找树。典型应用是用于统计，排序和保存大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。
![前缀树.png](https://pic.leetcode-cn.com/610618976202d3973f5a4866d3908c35051ce8ae774be8eaad635ba9d259c8c6-%E5%89%8D%E7%BC%80%E6%A0%91.png)
从根节点往下，每条边标识一个字符。
- 在查询一个字符串时，可以顺着根节点往下比较。一直到叶子节点
- 在查询前缀时也是如此，只不过不用到叶子节点

### 构造字典树 与 查询、插入 操作
1. 数据结构
```javascript []
var Trie = function() {
    this.root = new TrieNode()
};
var TrieNode = function(){
    this.next = new Map(); //map存取节点的出度。
    this.isEnd = false; //某些单词可能是另一个单词前缀。true表示到此结束有单词。
}
```
2. 插入单词
```javascript []
Trie.prototype.insert = function(word) {
    if(!word) return;
    var node = this.root;
    for(let i=0;i<word.length;i++){
        if(!node.next.has(word[i])){
            node.next.set(word[i],new TrieNode());            
        }
        node = node.next.get(word[i])
    }
    node.isEnd = true;    
};
```
3. 搜寻单词
```javascript []
Trie.prototype.search = function(word) {
    if(! word) return false;
    var node = this.root;
    for(let i=0;i<word.length;i++){
        if(! node.next.has(word[i])){
            return false;
        }
        node = node.next.get(word[i]);
    }
    return node.isEnd;
};
```
4. 搜寻前缀
```javascript []
Trie.prototype.startsWith = function(prefix) {
    if(! prefix) return true;
    var node = this.root;
    for(let i=0;i<prefix.length;i++){
        if(! node.next.has(prefix[i])){
            return false;
        }
        node = node.next.get(prefix[i]);
    }
    return true;
};
```


## 整合代码

```javascript
/**
 * Initialize your data structure here.
 */
var Trie = function() {
    this.root = new TrieNode()
};
/**
 * TrieNode
 */
function TrieNode(){
    this.next = new Map();
    this.isEnd = false;
}


/**
 * Inserts a word into the trie. 
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
    if(!word) return;
    var node = this.root;
    for(let i=0;i<word.length;i++){
        if(!node.next.has(word[i])){
            node.next.set(word[i],new TrieNode());            
        }
        node = node.next.get(word[i])
    }
    node.isEnd = true;    
};

/**
 * Returns if the word is in the trie. 
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word) {
    if(! word) return false;
    var node = this.root;
    for(let i=0;i<word.length;i++){
        if(! node.next.has(word[i])){
            return false;
        }
        node = node.next.get(word[i]);
    }
    return node.isEnd;
};

/**
 * Returns if there is any word in the trie that starts with the given prefix. 
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function(prefix) {
    if(! prefix) return true;
    var node = this.root;
    for(let i=0;i<prefix.length;i++){
        if(! node.next.has(prefix[i])){
            return false;
        }
        node = node.next.get(prefix[i]);
    }
    return true;
};

/**
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */
```