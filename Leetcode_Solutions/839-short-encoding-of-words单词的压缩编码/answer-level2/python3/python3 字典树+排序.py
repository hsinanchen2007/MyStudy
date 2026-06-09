### 解题思路
想的复杂了，逆序构造字典树。
从最长的单词开始查询字典树，如果能查到，说明被包含，无需计算。如果不能查到，插入字典树并计算长度。

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words.sort(key=lambda x:len(x), reverse=True)
        res = []
        trie = Trie()
        for word in words:
            if not trie.search(word[::-1]):
                trie.insert(word[::-1])
                res.append(word)
        
        return len(res) + sum(len(i) for i in res)

class Trie:
    def __init__(self):
        self.tree = {}
        self.isWord = -1
    
    def insert(self, word):
        cur = self.tree
        for c in word:
            if c not in cur:
                cur[c] = {}
            cur = cur[c]
        cur[self.isWord] = True
    
    def search(self, word):
        cur = self.tree
        for c in word:
            if c not in cur:
                return False
            cur = cur[c]
        return True
```