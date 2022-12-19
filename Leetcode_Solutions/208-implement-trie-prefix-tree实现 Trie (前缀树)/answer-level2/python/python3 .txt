### 解题思路
纪念自己的python class代码，需要复习基础知识了

### 代码

```python3
class TrieNode:
    def __init__(self):
        self.isEnd = False
        self.next = [None]*26

class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root=TrieNode()

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        p = self.root
        for s in word:
            if p.next[ord(s)-ord('a')] == None:
                p.next[ord(s)-ord('a')] = TrieNode()
            p = p.next[ord(s)-ord('a')]
        p.isEnd = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        p = self.root
        for s in word:
            p = p.next[ord(s)-ord('a')]
            if p == None:
                return False
        return p.isEnd

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        p = self.root
        for s in prefix:
            p = p.next[ord(s)-ord('a')]
            if p == None:
                return False
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
```