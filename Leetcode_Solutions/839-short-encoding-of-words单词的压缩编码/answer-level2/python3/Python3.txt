### 解题思路
前缀树

### 代码

```python3
class TrieNode:
    def __init__(self, offset=0):
        self.next = {}
        self.offset = offset
        self.isEnd = False

class Trie:
    def __init__(self,):
        self.root = TrieNode()
    
    def insert(self, s, index):
        cur = self.root
        for i, x in enumerate(s):
            if x not in cur.next:
                cur.next[x] = TrieNode(index - 1 - i)
            cur = cur.next[x]
        cur.isEnd = True
    
    def searchPrefix(self, prefix):
        cur = self.root
        for i in prefix:
            if i not in cur.next:
                return -1
            cur = cur.next[i]
        return cur.offset
        
        
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        cur, res, trie = 0, [], Trie()
        words.sort(key=len, reverse=True)
        for word in words:
            index = trie.searchPrefix(word[::-1])
            if index < 0:
                res.append(cur)
                cur += len(word) + 1
                trie.insert(word[::-1], cur - 1)
            else:
                res.append(index)
        return cur

            
            
            
            
```