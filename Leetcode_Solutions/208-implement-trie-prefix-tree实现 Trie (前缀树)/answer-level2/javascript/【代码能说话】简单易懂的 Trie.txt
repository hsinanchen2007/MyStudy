```javascript
/**
 * Initialize your data structure here.
 */
var TrieNode = function (val) {
  // 当前节点的值
  this.val = val
  // 当前节点是否为某个单词的最后一个字母，若是，则代表是一个单词
  this.isWord = false
  // 子节点
  this.children = new Map()
}

var Trie = function() {
  this.root = new TrieNode(null)
};

/**
 * Inserts a word into the trie. 
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
  let cur = this.root
  const len = word.length
  // 将单词插入到树中
  for (let i = 0; i < len; i++) {
    const char = word[i]
    if (!cur.children.has(char)) {
      cur.children.set(char, new TrieNode(char))
    }
    cur = cur.children.get(char)
    // 遍历到结尾的时候将 isWord 设为 true
    if (i === len - 1) {
      cur.isWord = true
    }
  }
};

/**
 * Returns if the word is in the trie. 
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word) {
  let cur = this.root
  for (let char of word) {
    // 如果该字符不在 children 中，说明是新单词
    if (!cur.children.has(char)) {
      return false
    }
    cur = cur.children.get(char)
  }
  // 若顺利遍历完该单词，则进行判断该单词最后一个字母所在节点的 isWord 是否为真
  // 因为存在 key(未插入) / keyword(已插入) 这种情况
  return cur.isWord
};

/**
 * Returns if there is any word in the trie that starts with the given prefix. 
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function(prefix) {
  // 与 search 方法相比，该方法只需要判断能否成功遍历所有字符
  let cur = this.root
  for (let char of prefix) {
    if (!cur.children.has(char)) {
      return false
    }
    cur = cur.children.get(char)
  }
  return true
};
```
