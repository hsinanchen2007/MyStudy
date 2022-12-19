### 解题思路
先写的前置树，再写这个。

### 代码

```python3
class TrieNode:
    def __init__(self,dep):
        self.depth = dep
        self.next = [None]*26

class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root=TrieNode(1)

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        p = self.root
        dep = 0
        for s in word:
            dep = dep + 1
            if p.next[ord(s)-ord('a')] == None:
                p.next[ord(s)-ord('a')] = TrieNode(dep+1)
            p = p.next[ord(s)-ord('a')]

    def count(self,root):
        "返回所有叶子节点的长度"
        p = root
        res = 0
        if p.next == [None]*26:
            return p.depth
        else :
            for k in p.next:
                if k is not None:
                    res += self.count(k)
        return res

class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        rs_words = []
        for k in words:
            l_k=len(k)
            rs_words.append(k[::-1])
        rs_words = sorted(rs_words,key = lambda i:len(i),reverse = True)
        root = Trie()
        for k in rs_words:
            root.insert(k)
        return root.count(root.root)
```