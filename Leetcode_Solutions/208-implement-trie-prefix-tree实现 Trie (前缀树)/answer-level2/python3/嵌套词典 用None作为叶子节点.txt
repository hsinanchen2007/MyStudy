啥也不说了，算法很简单，show me the code.

```
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._data = {}

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        p = self._data
        for s in word:
            if s not in p:
                p[s] = {}
            p = p[s]    
        p[None] = None # mark as a leaf node

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        p = self._data
        for s in word:
            if s in p:
                p = p[s]
            else:
                return False
        return None in p # check leaf Node

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        p = self._data
        for s in prefix:
            if s in p:
                p = p[s]
            else:
                return False
        return bool(p) # whether the node is empty
        
```