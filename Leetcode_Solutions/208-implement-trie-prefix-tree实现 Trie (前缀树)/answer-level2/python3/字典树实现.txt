### 解题思路
此处撰写解题思路

### 代码

```python3
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.children={}
        self.end = False

        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        root = self
        for c in word:
            if c not in root.children:
                root.children[c]=Trie()
            root=root.children[c]
        root.end = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        root = self
        for c in word:
            if c in root.children:
                root = root.children[c]
            else:
                return False
        return root.end
                
        

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        root = self
        for c in prefix:
            if c in root.children:
                root = root.children[c]
            else:
                return False
        return True



# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
```